/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // 1. Schedule the function execution
    const timerId = setTimeout(() => {
        fn(...args);
    }, t);

    // 2. Return the cancellation function
    return function cancelFn() {
        clearTimeout(timerId);
    };
};