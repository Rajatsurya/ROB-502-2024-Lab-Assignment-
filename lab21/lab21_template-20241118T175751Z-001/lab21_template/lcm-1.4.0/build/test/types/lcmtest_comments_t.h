// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#ifndef _lcmtest_comments_t_h
#define _lcmtest_comments_t_h

#include <stdint.h>
#include <stdlib.h>
#include <lcm/lcm_coretypes.h>
#include <lcm/lcm.h>
#include "lcmtest_export.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LCMTEST_COMMENTS_T_const_field 5

/// Contains a number of primitive data types
typedef struct _lcmtest_comments_t lcmtest_comments_t;
struct _lcmtest_comments_t
{
    /// Comments immediately preceding a field are attached to that field.
    int8_t     field_a;
    /**
     * Both single line comments.
     *  And multi-line
     * comments.
     *
     */
    int16_t    field_b;
    /**
     * Test empty comments.
     *
     */
    int32_t    field_c;
    /**
     *
     *
     */
    int64_t    field_d;
    /**
     *
     *
     */
    float      field_e;
    int32_t    *array;
};

/**
 * Create a deep copy of a lcmtest_comments_t.
 * When no longer needed, destroy it with lcmtest_comments_t_destroy()
 */
LCMTEST_EXPORT lcmtest_comments_t* lcmtest_comments_t_copy(const lcmtest_comments_t* to_copy);

/**
 * Destroy an instance of lcmtest_comments_t created by lcmtest_comments_t_copy()
 */
LCMTEST_EXPORT void lcmtest_comments_t_destroy(lcmtest_comments_t* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _lcmtest_comments_t_subscription_t lcmtest_comments_t_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * lcmtest_comments_t is received.
 */
typedef void(*lcmtest_comments_t_handler_t)(
    const lcm_recv_buf_t *rbuf, const char *channel,
    const lcmtest_comments_t *msg, void *userdata);

/**
 * Publish a message of type lcmtest_comments_t using LCM.
 *
 * @param lcm The LCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means LCM has transferred
 * responsibility of the message data to the OS.
 */
LCMTEST_EXPORT int lcmtest_comments_t_publish(lcm_t *lcm, const char *channel, const lcmtest_comments_t *msg);

/**
 * Subscribe to messages of type lcmtest_comments_t using LCM.
 *
 * @param lcm The LCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by LCM when a message is
 *     received. This function is invoked by LCM during calls to lcm_handle()
 *     and lcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return 0 on success, <0 if an error occured
 */
LCMTEST_EXPORT lcmtest_comments_t_subscription_t* lcmtest_comments_t_subscribe(
    lcm_t *lcm, const char *channel, lcmtest_comments_t_handler_t handler, void *userdata);

/**
 * Removes and destroys a subscription created by lcmtest_comments_t_subscribe()
 */
LCMTEST_EXPORT int lcmtest_comments_t_unsubscribe(lcm_t *lcm, lcmtest_comments_t_subscription_t* hid);

/**
 * Sets the queue capacity for a subscription.
 * Some LCM providers (e.g., the default multicast provider) are implemented
 * using a background receive thread that constantly revceives messages from
 * the network.  As these messages are received, they are buffered on
 * per-subscription queues until dispatched by lcm_handle().  This function
 * how many messages are queued before dropping messages.
 *
 * @param subs the subscription to modify.
 * @param num_messages The maximum number of messages to queue
 *  on the subscription.
 * @return 0 on success, <0 if an error occured
 */
LCMTEST_EXPORT int lcmtest_comments_t_subscription_set_queue_capacity(
    lcmtest_comments_t_subscription_t* subs, int num_messages);

/**
 * Encode a message of type lcmtest_comments_t into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to lcmtest_comments_t_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
LCMTEST_EXPORT int lcmtest_comments_t_encode(void *buf, int offset, int maxlen, const lcmtest_comments_t *p);

/**
 * Decode a message of type lcmtest_comments_t from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with lcmtest_comments_t_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
LCMTEST_EXPORT int lcmtest_comments_t_decode(const void *buf, int offset, int maxlen, lcmtest_comments_t *msg);

/**
 * Release resources allocated by lcmtest_comments_t_decode()
 * @return 0
 */
LCMTEST_EXPORT int lcmtest_comments_t_decode_cleanup(lcmtest_comments_t *p);

/**
 * Check how many bytes are required to encode a message of type lcmtest_comments_t
 */
LCMTEST_EXPORT int lcmtest_comments_t_encoded_size(const lcmtest_comments_t *p);

// LCM support functions. Users should not call these
LCMTEST_EXPORT int64_t __lcmtest_comments_t_get_hash(void);
LCMTEST_EXPORT uint64_t __lcmtest_comments_t_hash_recursive(const __lcm_hash_ptr *p);
LCMTEST_EXPORT int __lcmtest_comments_t_encode_array(
    void *buf, int offset, int maxlen, const lcmtest_comments_t *p, int elements);
LCMTEST_EXPORT int __lcmtest_comments_t_decode_array(
    const void *buf, int offset, int maxlen, lcmtest_comments_t *p, int elements);
LCMTEST_EXPORT int __lcmtest_comments_t_decode_array_cleanup(lcmtest_comments_t *p, int elements);
LCMTEST_EXPORT int __lcmtest_comments_t_encoded_array_size(const lcmtest_comments_t *p, int elements);
LCMTEST_EXPORT int __lcmtest_comments_t_clone_array(const lcmtest_comments_t *p, lcmtest_comments_t *q, int elements);

#ifdef __cplusplus
}
#endif

#endif
