function foo() {
    return fiatInt52(Math.sqrt(2)) + 1;
}

noInline(foo);

for (var i = 0; i < testLoopCount; ++i) {
    var result = foo();
    if (result != Math.sqrt(2) + 1)
        throw "Error: bad result: " + result;
}
