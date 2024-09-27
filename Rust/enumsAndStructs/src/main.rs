#![allow(unused)]


fn main() {
    enum_stuff();

    let new_point = Point(10, 10);

    match new_point {
        Point(p1, p2) => {
            println!("point 1 {}, point 2 {}", p1, p2);
        }
    }

    println!("{}, {}", new_point.0, new_point.1);

    do_stuff();


}

//ENUMS AND STRUCTS

struct  Circle {
    rad: f64,
}

struct  Rect {
    wid: f64,
    hei: f64,
}

enum NewShape {
    Circle(Circle),
    Rect(Rect),
}

fn do_stuff ()
{
    let shape_1 = NewShape::Circle(Circle{rad: 3.0});
    let shape_2 = NewShape::Rect(Rect { wid: 20.0, hei: 20.0 });

    match shape_1 {
        NewShape::Circle(ref  circle) => {
            println!(" radius {}", circle.rad);
        }
        NewShape::Rect(ref rect) => {
            println!("width {}, height {}", rect.wid, rect.hei);
        }
    }

    match shape_2 {
        NewShape::Circle(ref circle) => {
            println!("radius {}", circle.rad);
        }
        NewShape::Rect(ref rect) => {
            println!("width {}, height {}", rect.wid, rect.hei);
        }
    }
}

//ENUMS
fn enum_stuff()
{
    let move_dir1 = Dir::UP;
    let move_dir2 = Dir::RIGHT;
    let move_dir3 = Dir::LEFT;
    let move_dir4 = Dir::DOWN;

    match move_dir1 {
        Dir::UP => println!("moving up"),
        Dir::DOWN => println!("moving doiw"),
        Dir::LEFT => println!("moving left"),
        Dir::RIGHT => println!("moving rght")
    }

    let shape = Shape::Square(3.0);

    match shape {
        Shape::Circle(radius) => {
            println!("radius {}",  radius);
        }
        Shape::Rect(len1,len2 ) => {
            println!("len 1 {}, len2 {}", len1, len2);
        }
        Shape::Square(side) => {
            println!("side {}", side);
        }
    }

    let new_person = Person {
        name: String::from("kol"),
        age: 30,
    };

    println!("{}, {}", new_person.name, new_person.age);

}


enum Dir{
    UP,
    DOWN,
    LEFT,
    RIGHT,
}

enum Shape {
    Circle(f64),
    Rect(f64, f64),
    Square(f64),
}

//STRUCTS

struct Person {
    name: String,
    age: u32,
}

struct Point(i32, i32);