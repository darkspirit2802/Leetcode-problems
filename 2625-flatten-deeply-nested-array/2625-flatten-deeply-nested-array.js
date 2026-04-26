/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function(arr, n) {
    const result = [];
    
    function dfs(current, depth) {
        for (let el of current) {
            if (Array.isArray(el) && depth > 0) {
                dfs(el, depth - 1);
            } else {
                result.push(el);
            }
        }
    }
    
    dfs(arr, n);
    return result;
};