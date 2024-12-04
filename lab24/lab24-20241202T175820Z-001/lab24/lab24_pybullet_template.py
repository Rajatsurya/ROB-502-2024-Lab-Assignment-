import math
import time
import numpy as np

import pybullet as p
import pybullet_data as pd


class PandaSim:

    def __init__(self):
        p.connect(p.GUI)

        # Use Y-up instead of Z-up, don't do this!
        # We borrowed this from an example that did it this way.
        p.configureDebugVisualizer(p.COV_ENABLE_Y_AXIS_UP, 1)
        p.resetDebugVisualizerCamera(cameraDistance=1, cameraYaw=60, cameraPitch=-30,
                                     cameraTargetPosition=np.array([0, 0.3, 0]))

        # Physics sim parameters
        self.dt = 1. / 100
        self.controller_steps = 100
        p.setTimeStep(self.dt)
        p.setGravity(0, -9.8, 0)

        # Load assets
        pth = pd.getDataPath()
        p.setAdditionalSearchPath(pth)

        self.default_joint_pos = [0.98, 0.1, 0.1, -2.24, -0.30, 2.66, 2.32, 0.02, 0.02]

        # --- Your code here
        #load pplane
        self.plane = p.loadURDF("plane.urdf",np.array([0.0,0.0,0.0]), p.getQuaternionFromEuler([-np.pi/2, 0, 0]))

        #load Panda
        self.panda = p.loadURDF(
            "assets/franka_panda/panda.urdf",
            basePosition=np.array([0, 0, 0]),
            baseOrientation=p.getQuaternionFromEuler([-np.pi/2, 0, 0]),
            useFixedBase=True,  # Recommended for manipulators
            flags=p.URDF_USE_SELF_COLLISION,  # Enable self-collision checking
            globalScaling=1.0  # Adjust size if needed
        )
        
        #setup panda arm
        index = 0
        for i in range(p.getNumJoints(self.panda)):
            joint_info = p.getJointInfo(self.panda, i)
            p.changeDynamics(self.panda, i, linearDamping=10, angularDamping=10, jointLowerLimit=-99, jointUpperLimit=99)

            joint_type = joint_info[2] # joint_info comes from p.getJointInfo 
            if (joint_type == p.JOINT_PRISMATIC) or (joint_type == p.JOINT_REVOLUTE): 
                p.resetJointState(self.panda, i, self.default_joint_pos[index]) 
                index = index + 1 

        # ---

    def step(self):
        # --- Your code here
        for t in range (self.controller_steps):
            p.stepSimulation()
            time.sleep(self.dt)
        # ---

    def get_joint_state(self):
        """
            Gets current joint angles
        :return: state: 7 joint angles
        """
        # --- Your code here
        state = np.zeros(7)
        for i in range(7):
            state[i]=p.getJointState(self.panda, i)[0]
        return state
        # ---

    def set_joint_state(self, state):
        """
            Sets the joint state via the controller and simulates
        :param
            state: 7 joint angles
        """
        # --- Your code here
        for i in range(7):
            p.setJointMotorControl2(self.panda, i, p.POSITION_CONTROL, state[i], force=100)
        self.step()
        # ---

    def get_gripper_position(self):
        # --- Your code here
        pandaEndEffectorIndex = 11
        link_state = p.getLinkState(self.panda, pandaEndEffectorIndex)
        return link_state[0]  # Returns the position (x,y,z) from link_state
        # ---


def main():
    panda_sim = PandaSim()

    # --- Your code here
    panda_sim.set_joint_state([1.98, 0.5, 0.1, -2.24, -0.30, 2.66, 2.32])
    gripper_pos = panda_sim.get_gripper_position()
    print(f"Gripper X position: {gripper_pos[0]}")
    
    for _ in range(1000):
        panda_sim.step()
    # ---

    time.sleep(5)


if __name__ == '__main__':
    main()