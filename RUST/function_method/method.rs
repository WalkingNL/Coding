struct Point {
    x: f64,
    y: f64,
}

impl Point {
    fn origin() -> Point {
        Point { x: 0.0, y: 0.0 }
    }
    fn new(x: f64, y: f64) -> Point {
        Point{ x: x, y: y }
    }
}

struct Rectangle {
    p1: Point,
    p2: Point,
}

impl Rectangle {
    fn init() -> Rectangle {
        Rectangle {
            p1: Point::origin(),
            p2: Point::new(10.0, 11.0),
        }
    }
    fn area(&self) -> f64 {
        ((self.p1.x - self.p2.x) * (self.p1.y - self.p2.y)).abs()
    }
    fn perimeter(&self) -> f64 {
        2.0 * ((self.p1.x - self.p2.x) + (self.p1.y - self.p2.y)).abs()
    }
    fn translate(&mut self, x: f64, y: f64) {
        self.p1.x += x;
        self.p2.x += y;
        self.p1.y += x;
        self.p2.y += y;
    }
}

// `Pair` owns resources: two heap allocated integers
// struct Pair(Box<i32>, Box<i32>); // tuple struct
struct Pair { //Name field struct
    p1: Box<i32>,
    p2: Box<i32>,
}

impl Pair {
    // This method "consumes" the resources of the caller object
    // `self` desugars to `self: Self`
    fn constructor(i: i32, j: i32) -> Pair {
        Pair {
            p1: Box::new(i),
            p2: Box::new(j),
        }
    }
    fn destroy(self) {
        // Destructure `self`
        let pair = self;

        println!("Destroying Pair({}, {})", pair.p1, pair.p2);

        // `first` and `second` go out of scope and get freed
    }
}

//
struct PairX { //Name field struct
    p1: Box<Point>,
    p2: Box<Point>,
}

impl PairX {
    // This method "consumes" the resources of the caller object
    // `self` desugars to `self: Self`
    fn constructor() -> PairX {
        PairX {
            p1: Box::new(Point::new(10.0, 20.0)),
            p2: Box::new(Point::new(100.0, 200.0)),
        }
    }
    fn destroy(self) {
        // Destructure `self`
        let pairx = self;

        println!("Destroying PairX({}, {})", pairx.p1.x, pairx.p2.y);

        // `first` and `second` go out of scope and get freed
    }
}

fn main() {
    let p = Point::new(3.0, 5.0);
    println!("{}, {}", p.x, p.y);

    let mut p2 = Point::origin();
    println!("{}, {}", p2.x, p2.y);
    p2.x = 10.0;
    p2.y = 20.0;
    println!("{}, {}", p2.x, p2.y);

    let mut r = Rectangle::init();
    // println!("{}", r.area());
    // println!("{}", r.perimeter());
    println!("before: x:{}, y:{}, area:{}, perimeter:{}", r.p1.x, r.p1.y, r.area(), r.perimeter());

    r.translate(10.0, 20.0);
    println!("before: x:{}, y:{}, area:{}, perimeter:{}", r.p1.x, r.p1.y, r.area(), r.perimeter());

    // let pair = Pair(Box::new(1000), Box::new(2000));
    let pair = Pair::constructor(10, 20);

    pair.destroy();

    let pair_x = PairX::constructor();
    pair_x.destroy();
}

