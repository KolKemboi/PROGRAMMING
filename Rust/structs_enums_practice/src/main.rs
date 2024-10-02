


fn main() {
    exe_1();
}



fn exe_2()
{
    struct BookInfo {
        get_summary: String,
        is_expensive: f64,
    }


}

fn exe_1()
{
    struct Book{
        title: String,
        author: String,
        pages: u32,
        price: f64,
    }

    impl Book {
        fn new(title: String, author: String, pages: u32, price:f64) -> Book
        {
           return  Book {
                title,
                author,
                pages,
                price,
        };
        }
        
        fn out_info(&self)
        {
            println!("{}, {}, {}, {}", self.title, self.author, self.pages, self.price)
        }
    }
    

    let new_book = Book::new("kol".to_string(), "col".to_string(), 10, 10.0);

    new_book.out_info();
}