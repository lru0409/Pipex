# Pipex
- **파이프와 리다이렉션**을 프로그래밍해보는 프로젝트다.
- 쉘이 파이프와 연결된 명령어들과 리다이렉션을 어떻게 처리하는지 깊게 탐구해 볼 수 있었다.

이 프로젝트를 하면서 다음과 같은 것들을 배울 수 있었다.
1. 유닉스 시스템의 파일 디스크립터
2. **표준 입출력의 방향을 바꿔주는 리다이렉션**
3. **프로세스 간 통신을 지원하는 파이프와 그의 작동 방식**
4. **파이프의 읽기 끝/쓰기 끝을 적절히 닫아 주어야 하는 이유**
6. 쉘이 파이프로 연결된 명령들을 병렬적으로 수행한다는 점
7. 부모 프로세스와 별개의 실행 흐름을 가지는 자식 프로세스를 생성하고, 잃어버리지 않는 방법

## 요구 사항
- 이 셸 명령과 정확히 똑같이 동작하는 프로그램 pipex를 구현하자.   
	- `$> < file1 cmd1 | cmd2 > file2`
- pipex 프로그램은 fild1, cmd1, cmd2, file2를 인자로 받는다.    
	- `./pipex file1 cmd1 cmd2 file2`
- 발생할 수 있는 오류를 예상하여 철저히 처리해야 한다. 에러 핸들링은 셸을 참고하자.
- 보너스에서는 다중 파이프와 히어독을 처리해야 한다.     
  - 다중 파이프: `$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
  - 히어독: `$> cmd << LIMITER | cmd1 ... | cmdn >> file` 

## 프로그램 실행
- `make`로 mandatory의 pipex 실행 파일, `make bonus`로 bonus의 pipex 실행 파일을 얻을 수 있다.   
- 다음과 같이 pipex 프로그램을 실행시켜 볼 수 있다.     
- 단, infile.txt 파일을 직접 생성한 후에 실행해야 정상 작동한다. (셸도 이와 같이 동작함)
```shell
./pipex infile.txt cat "wc -l" outfile.txt # mandatory
./pipex infile.txt cat "grep a" "wc -l" outfile.txt # bonus
./pipex here_doc END cat "grep a" "wc -l" outfile.txt # bonus
```

##
학습 내용과 프로젝트 진행 과정에 대한 자세한 이야기는 [여기서](https://velog.io/@ronn/Pipex-%EC%89%98%EC%9D%98-%ED%8C%8C%EC%9D%B4%ED%94%84%EC%99%80-%EB%A6%AC%EB%8B%A4%EC%9D%B4%EB%A0%89%EC%85%98%EC%9D%84-%EA%B5%AC%ED%98%84%ED%95%98%EC%9E%90) 확인할 수 있다.
