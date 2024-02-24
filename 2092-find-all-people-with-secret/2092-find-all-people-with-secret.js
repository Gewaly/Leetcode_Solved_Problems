/**
 * @param {number} n
 * @param {number[][]} meetings
 * @param {number} firstPerson
 * @return {number[]}
 */
var findAllPeople = function(n, meetings, firstPerson) {
    let knownSet = new Set([0, firstPerson]);
    
    meetings.sort((a, b) => a[2] - b[2]);

    let sortedMeetings = [];
    let seenTime = new Set(); 
    
    // Group meetings by time.
    for (let meeting of meetings) {
        if (!seenTime.has(meeting[2])) {
            seenTime.add(meeting[2]);
            sortedMeetings.push([]);
        }
        sortedMeetings[sortedMeetings.length - 1].push([meeting[0], meeting[1]]);
    }

    // Iterate through each group of meetings.
    for (let meetingGroup of sortedMeetings) {
        let peopleKnowSecret = new Set(); 
        let graph = {}; 
        
        for (let [p1, p2] of meetingGroup) {
            if (!graph[p1]) graph[p1] = [];
            if (!graph[p2]) graph[p2] = [];
            
            graph[p1].push(p2);
            graph[p2].push(p1);
            
            if (knownSet.has(p1)) peopleKnowSecret.add(p1);
            if (knownSet.has(p2)) peopleKnowSecret.add(p2);
        }
        
        let queue = [...peopleKnowSecret];
        while (queue.length > 0) {
            let curr = queue.shift();
            knownSet.add(curr);
            for (let neigh of graph[curr]) {
                if (!knownSet.has(neigh)) {
                    knownSet.add(neigh);
                    queue.push(neigh);
                }
            }
        }
    }

    return [...knownSet];
};