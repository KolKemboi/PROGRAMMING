fn main() {
    
    let mut user = User::new("kol_user".to_string(), "kol@gmail.com".to_string());
    user.activate();
    println!("{}", user.email);
    println!("{}", user.username);
    println!("{}", user.sign_in_count);
    println!("{}", user.active);
    user.deactivate();
    println!("{}", user.active);
    user.greet();


    let mut new_model = Other::_other("name_of_model".to_string());
    new_model.greet();
    new_model.print_model_name();

}



struct User 
{
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

impl User
{
    fn new(username: String, email: String) -> User
    {
        User
        {
            username,
            email,
            sign_in_count: 1,
            active: true
        }
    }

    fn activate(&mut self)
    {
        self.active = true;
    }
    fn deactivate(&mut self)
    {
        self.active = false;
    }

}

trait Greet
{
    fn greet(&self);    
}

impl Greet for User
{
    fn greet(&self) {
        println!("hello, {}", self.username);
    }
}

struct Other
{
    model: String
}

impl Other  
{
    fn _other(name_of_model: String) -> Other
    {
        Other
        {
            model: name_of_model,
        }
    }

    fn print_model_name(&mut self)
    {
        println!("{}", self.model);
    }
}
impl Greet for Other
{
    fn greet(&self) {
        println!("hello, {}", self.model);
    }    
}