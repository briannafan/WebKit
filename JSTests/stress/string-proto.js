function shouldBe(actual, expected) {
    if (actual !== expected)
        throw new Error('bad value: ' + actual);
}

function target(value)
{
    return value.__proto__;
}
noInline(target);
for (var i = 0; i < testLoopCount; ++i)
    shouldBe(target("Cocoa"), String.prototype)
