use std::io;

fn main() {
    let mut input = String::new();

    // 행과 열의 크기 입력
    println!("첫 번째 행렬의 행 수 입력: ");
    io::stdin().read_line(&mut input).expect("입력 실패");
    let rows: usize = input.trim().parse().expect("정수를 입력하세요.");
    input.clear();

    println!("첫 번째 행렬의 열 수 입력: ");
    io::stdin().read_line(&mut input).expect("입력 실패");
    let cols: usize = input.trim().parse().expect("정수를 입력하세요.");
    input.clear();

    // 두 개의 행렬을 저장하기 위한 Vec 초기화
    let mut matrix1: Vec<Vec<i32>> = vec![vec![0; cols]; rows];
    let mut matrix2: Vec<Vec<i32>> = vec![vec![0; cols]; rows];
    let mut result: Vec<Vec<i32>> = vec![vec![0; cols]; rows];

    // 첫 번째 행렬 입력
    println!("첫 번째 행렬의 요소를 입력하세요:");
    for i in 0..rows {
        for j in 0..cols {
            io::stdin().read_line(&mut input).expect("입력 실패");
            matrix1[i][j] = input.trim().parse().expect("정수를 입력하세요.");
            input.clear();
        }
    }

    // 두 번째 행렬 입력
    println!("두 번째 행렬의 요소를 입력하세요:");
    for i in 0..rows {
        for j in 0..cols {
            io::stdin().read_line(&mut input).expect("입력 실패");
            matrix2[i][j] = input.trim().parse().expect("정수를 입력하세요.");
            input.clear();
        }
    }

    // 행렬 덧셈
    for i in 0..rows {
        for j in 0..cols {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // 결과 출력
    println!("행렬 덧셈 결과:");
    for i in 0..rows {
        for j in 0..cols {
            print!("{} ", result[i][j]);
        }
        println!();
    }
}
