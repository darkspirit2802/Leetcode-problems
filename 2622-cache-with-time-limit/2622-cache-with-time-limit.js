var TimeLimitedCache = function() {
    this.cache = new Map(); // Stores key -> {value, timeoutId}
};

/** * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const exists = this.cache.has(key);
    
    // If key exists, cancel the previous expiration timer
    if (exists) {
        clearTimeout(this.cache.get(key).timeoutId);
    }
    
    // Set a new timer to delete the key after duration
    const timeoutId = setTimeout(() => {
        this.cache.delete(key);
    }, duration);
    
    // Store the value and the timer reference
    this.cache.set(key, { value, timeoutId });
    
    return exists;
};

/** * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (this.cache.has(key)) {
        return this.cache.get(key).value;
    }
    return -1;
};

/** * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};