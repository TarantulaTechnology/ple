use std::io::Write; // Needed for writing to stderr

fn main() {
    let args = std::env::args();
    if args.len() != 2 {
        let _ = writeln!(std::io::stderr(), "Single argument required");
        std::process::exit(1);
    }
    if let Some(last_arg) = args.last() {
        let mut word: Vec<_> = last_arg.chars().collect();
        generate_permutations(word.len() - 1, &mut word);
    }
}

fn generate_permutations<'a>(n: usize, a: &'a mut Vec<char>) {
    if n == 0 {
        println!("{}", a.clone().into_iter().collect::<String>());
    } else {
        for i in 0..n+1 {
            generate_permutations(n - 1, a);
            a.swap(if n % 2 == 0 { i } else { 0 }, n);
        }
    }
}
