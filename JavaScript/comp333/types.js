// You can do ".load types.js" do load this in node

// This works with both strings and numbers
// Statically typed languages vs dynamic type have the advantage since we already know what
//      code needs to be run at compile time.
// That being say, there are stuff that could be written in dynamically typed languages that
//      you just can't in static. This add function is one of them

function add(x, y) {
    return x + y;
}

// This would be something else that can be written in js and not java, since java needs to
// explicitly say what the return type is and stick to it. There would be ways around it with an
// interface, but would be a lot more verbose.
function doSomething(a) {
    if (a < 3) {
        return 0
    } else {
        return "foo";
    }
}
