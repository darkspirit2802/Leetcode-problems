/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // 1. Call the function immediately
    fn(...args);

    // 2. Schedule the function to run every 't' milliseconds
    const timerId = setInterval(() => {
        fn(...args);
    }, t);

    // 3. Return the cancellation function
    return function cancelFn() {
        clearInterval(timerId);
    };
};