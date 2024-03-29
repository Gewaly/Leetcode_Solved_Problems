/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let a=0,b=1;
    while(1){
        yield a;
        [a,b] = [b,a+b];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */