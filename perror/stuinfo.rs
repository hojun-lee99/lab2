use std::collections::BTreeMap;
use std::io;

struct Student {
    mid_term_score: i32,
    final_score: i32,
}

fn main() {
    let mut input = String::new();

    println!("학생 수를 입력하세요: ");
    io::stdin().read_line(&mut input).expect("입력 실패");
    let num_students: usize = input.trim().parse().expect("정수를 입력하세요.");
    input.clear();

    let mut students: BTreeMap<String, Student> = BTreeMap::new();

    for _ in 0..num_students {
        println!("학생 이름: ");
        io::stdin().read_line(&mut input).expect("입력 실패");
        let name = input.trim().to_string();
        input.clear();

        println!("중간 점수: ");
        io::stdin().read_line(&mut input).expect("입력 실패");
        let mid_term_score: i32 = input.trim().parse().expect("정수를 입력하세요.");
        input.clear();

        println!("기말 점수: ");
        io::stdin().read_line(&mut input).expect("입력 실패");
        let final_score: i32 = input.trim().parse().expect("정수를 입력하세요.");
        input.clear();

        students.insert(name, Student { mid_term_score, final_score });
    }

    println!("찾을 학생 이름을 입력하세요: ");
    io::stdin().read_line(&mut input).expect("입력 실패");
    let search_name = input.trim().to_string();

    match students.get(&search_name) {
        Some(student) => {
            println!("학생 이름: {}", search_name);
            println!("중간 점수: {}", student.mid_term_score);
            println!("기말 점수: {}", student.final_score);
        }
        None => {
            println!("학생을 찾을 수 없음.");
        }
    }
}
