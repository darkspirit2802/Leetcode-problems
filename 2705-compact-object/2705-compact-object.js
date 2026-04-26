/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        const res = [];
        for (let val of obj) {
            if (Boolean(val)) {
                const compacted = compactObject(val);
                res.push(compacted);
            }
        }
        return res;
    } 
    
    if (obj !== null && typeof obj === "object") {
        const res = {};
        for (let key in obj) {
            if (Boolean(obj[key])) {
                const compacted = compactObject(obj[key]);
                res[key] = compacted;
            }
        }
        return res;
    }
    
    return obj;
};