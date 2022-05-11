# computergraphics_miniproject

## 목적
**opengl로 3D 게임 구현**

* 게임 종류 : 추리 게임   
* 게임 기능 : 단서 조사, 사건 재구성   
* 게임 소개 : 하나의 크라임씬을 조사하고 이를 기반으로 추리하여 범인을 찾아내는 게임   
* 게임 방법 : 각각의 단서를 select하면, 단서를 자세히 출력하고 모든 단서를 수집한 후, 사건을 추리하여 정답이면 게임 clear   


## 게임 인터페이스 구현
|입력|출력|
|---|---|
|w, s, a, d| 앞/뒤/좌/우 이동|
|방향키|시야회전|
|마우스 클릭|object 선택|
|메뉴|화면전환, 게임종료, object 취소|

## 파일
* bmpfuncs.h bmpfuncs.h : bmp 파일 로드
* ObjParser.h : obj 파일 로드
* draw.h : object draw
* main.cpp : 기능 구현 파일

## 화면 구현
### blender로 사건 현장의 object들을 구현
<img width="592" alt="image" src="https://user-images.githubusercontent.com/77006790/167857120-edfa61a5-f83d-4c8a-9caa-1d3dec802cd7.png">

* 이후 object들에 texture mapping

### 처음 실행 화면
* * *
<img width="400" alt="image" src="https://user-images.githubusercontent.com/77006790/167857430-861a2ec0-80c7-42e1-af18-12ce9d9075af.png">

### 게임 실행 화면
* * *
<img width="350" alt="image" src="https://user-images.githubusercontent.com/77006790/167857496-28d0fbe0-99de-4883-8e0b-39d3ab8709eb.png">  <img width="300" alt="image" src="https://user-images.githubusercontent.com/77006790/167857529-f43a9441-4336-4394-8027-b26ed6ca6ba8.png">  <img width="300" alt="image" src="https://user-images.githubusercontent.com/77006790/167857539-735e3f8b-f3a4-4b34-a140-5d2f72194734.png">

### 게임 추리 화면
* * *
<img width="350" alt="image" src="https://user-images.githubusercontent.com/77006790/167857901-da17d39b-61f5-438f-97ed-1abf4dffc624.png">

## 프로젝트 진행 절차
||일정|
|---|---|
|1주차|주제 선정, 대략적인 계획 세우기|
|2주차|구체적인 계획 세우기|
|3주차|조명구현, 방 구현, 게임 인터페이스 구현, 문 회전 구현|
|4주차|blender로 object 구현|
|5주차|게임 인터페이스 수정, 방 크기 수정|
|6주차|picking 함수 구현, room와 room 내 object 구현 완료|
|7주차|picking시 event 구현, reasoning 화면 구현, bgm 추가|

* * *

* youtube : https://youtu.be/WUE-ij23yC0
