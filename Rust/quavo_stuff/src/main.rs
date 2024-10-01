#![allow(unused)]

fn main() {
    tick_struct();
    let string1 = String::from("Hello");
    let string2 = String::from("Helooooo");

    let string2 = longest(&string1, &string2);
    println!("{}", string2);

    let book = Book{title: &string1};
    book.print_title();

    let mut another = Another{ another: &string1};
    println!(" another      {}", another.do_self());

}

struct Another<'g> {
    another: &'g str,
}

impl <'g, 'h> Another<'g>
where 'g: 'h
{
    fn do_self(&self) -> &'h str
    {
        return  self.another;
    }    
}

struct  Excerpt<'d> {
    part: &'d str,
}

fn excerpt_fn<'d, 'e, 'f>(excerpt: &'e Excerpt<'d>) ->&'f str
where 'e: 'f
{
    return  excerpt.part;
}



struct Other<'b>
{
    title: &'b str,
}

impl<'b, 'c> Book<'b> 
where 'b: 'c
{
    fn get_title(&self) -> &'c str{
        return self.title;
    }
}


struct Book<'a> {
    title: &'a str,
}
impl<'a> Book<'a> {
    fn print_title(&self){
        println!("{}", self.title);
    }
}



fn longest<'a, 'b, 'c>(s1: &'a str, s2:&'a str) -> &'c str
where 'a: 'c, 'b: 'c
{
    if s1.len() > s2.len(){
        return s1;
    } else {
        return s2;
    }
}


struct Text<'a> {
    content: &'a str,
}

fn tick_struct()
{
    let sent = String::from("Hello, world");
    let text = Text{content: &sent};
    println!("{}", text.content);

}