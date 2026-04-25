/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const result = {};

    // Add all objects from the first array to our map
    for (const obj of arr1) {
        result[obj.id] = obj;
    }

    // Merge objects from the second array
    for (const obj of arr2) {
        if (result[obj.id]) {
            // If ID exists, merge properties. arr2 overrides arr1.
            result[obj.id] = { ...result[obj.id], ...obj };
        } else {
            // If ID is new, just add it
            result[obj.id] = obj;
        }
    }

    // Object.values gives us the objects, then we sort by id
    return Object.values(result).sort((a, b) => a.id - b.id);
};