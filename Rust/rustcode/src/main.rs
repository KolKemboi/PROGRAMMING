#![allow(unused)]

use core::error;
use std::io;
use std::iter::StepBy;
use rand::Rng;
use std::io::{Write, BufReader, BufRead, ErrorKind};
use std::fs::File;
use std::cmp::Ordering;

fn main()
{
    hello_world();
    var_types();
    more_var_types();

    let sum = add(3, 5);
    println!("{}", sum);

    control_flow();
    let mut name = String::new();
    name = usr_input();
    println!("{}", name);

    edit_string(&mut name);
    let string_size = string_size(&mut name);
    println!("{}", string_size);

    match error_handling(&mut name, 0) 
    {
        Ok(repeated)=>println!("{}", repeated),
        Err(e) => println!("Error: {}", e),

    }

    let user = User
    {
        usr_name: name.to_string(),
        age: 30,
    };

    println!("{}", user.describe());


}








//struct data type
struct User
{
    usr_name: String,
    age: u32,
}

//struct implementation
impl User 
{
    fn describe(&self) -> String
    {
        println!("      Structs");
        return format!("{} is {} years old", self.usr_name, self.age );
    }
}

//error handling in rust
fn error_handling(name_of_str: &mut String, times:usize) -> Result<String, &'static str>
{
    println!("      Error handling");
    if times == 0
    {
        return Err("cannot repeat zero times");
    }

    return Ok(name_of_str.repeat((times)));
}

//the len function
fn string_size(name_of_strng: &mut String) ->usize
{   
    println!("      getting the length");
    return name_of_strng.len();
}


//pushing 
fn edit_string(name_of_str: &mut String)
{
    println!("      String Editing");
    name_of_str.push_str(", string");
    println!("{}", name_of_str);
}

fn usr_input() ->String
{
    println!("      Usr Input");
    let mut name = String::new();
    io::stdin().read_line(&mut name).expect("didnt get a name");
    return  name;
}

fn control_flow()
{
    println!("      control flow and loops");
    let num = 7;
    if num < 5
    {
        println!("less")    
    }
    else
    {
        println!("more");    
    }

    for i in 1..num
    {
        println!("{}", i);
    }
}

fn add(a: i32, b: i32) ->i32
{
    println!("      addition");
    return a + b;
}

fn more_var_types()
{
    println!("      more var types");
    let a = 10;
    let b = 20.5;
    let c = true;
    let d = 'a';
    println!("{}", a);
    println!("{}", b);
    println!("{}", c);
    println!("{}", d);
}


fn var_types()
{
    println!("      var types");
    let x = 5;
    let mut y = 10;
    y += x;
    println!("{}", y);
}

fn hello_world()
{
    println!("Hello World");
}