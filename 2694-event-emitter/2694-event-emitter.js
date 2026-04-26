class EventEmitter {
    constructor() {
        this.events = {};
    }

    subscribe(eventName, callback) {
        if (!this.events[eventName]) {
            this.events[eventName] = [];
        }

        this.events[eventName].push(callback);

        return {
            unsubscribe: () => {
                const arr = this.events[eventName];
                if (!arr) return;

                const idx = arr.indexOf(callback);
                if (idx !== -1) {
                    arr.splice(idx, 1);
                }
            }
        };
    }

    emit(eventName, args = []) {
        const callbacks = this.events[eventName];
        if (!callbacks) return [];

        const result = [];
        for (let cb of callbacks) {
            result.push(cb(...args));
        }
        return result;
    }
}