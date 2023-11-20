/**
 * @param {string[]} garbage
 * @param {number[]} travel
 * @return {number}
 */
var garbageCollection = function (garbage, travel) {
    const vehicles = {
        P: { occurances: new Array(garbage.length).fill(0), lastOccurance: -1 },
        M: { occurances: new Array(garbage.length).fill(0), lastOccurance: -1 },
        G: { occurances: new Array(garbage.length).fill(0), lastOccurance: -1 },
    };

    for (let i = 0; i < garbage.length; i++) {
        const garbageTypes = garbage[i];

        for (let j = 0; j < garbageTypes.length; j++) {
            vehicles[garbageTypes[j]].occurances[i] += 1;
            vehicles[garbageTypes[j]].lastOccurance = i;
        }
    }
    let timeTaken = 0;
    const vehicleType = ['P', 'M', 'G'];

    for (let i = 0; i < 3; i++) {
        const vehicle = vehicles[vehicleType[i]];
        const lastOccurance = vehicle.lastOccurance;

        if (lastOccurance === -1) {
            continue;
        }

        for (let j = 0; j < garbage.length; j++) {
            if (j > lastOccurance) {
                break;
            }
            timeTaken += vehicle.occurances[j] + (travel[j - 1] || 0)
        }
    }

    return timeTaken;

};