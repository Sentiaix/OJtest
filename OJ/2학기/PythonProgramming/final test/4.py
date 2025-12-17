'''
PYTHON2025 2학기 컴공 
#소스코드 한글지원 안됩니다.

#----------------------------------------------------------------------------------------------------------------------------------------------------------
#문제: 동일 항공기에 대해 운항 시간이 서로 겹치는 비행편이 있는지 확인하는 프로그램을 구현하시오.
아래의 지시사항을 따라 코드를 작성하시오.

1. 함수 구현
  - is_overlap(start1, end1, start2, end2):
    • 매개변수: 네 개의 정수 (출발 시간1, 도착 시간1, 출발 시간2, 도착 시간2)
    • 두 구간 [start1, end1)과 [start2, end2)가 시간적으로 겹치면 True를, 겹치지 않으면 False를 반환한다.
    • 단, 한 비행의 도착 시간과 다른 비행의 출발 시간이 정확히 같은 경우는 겹치지 않는 것으로 간주한다.
      ex) [1, 3)와 [3, 5)는 False
  - count_conflicts(flights):
    • flights: [(plane_id, tart_time, end_time), ...] 튜플을 인자로 하는 리스트
    • 같은 plane_id를 가진 비행편들 중 시간이 겹치는 비행평의 개수를 센다.
    • 한 항공기에 대해 두 비행편이 겹치면 충돌 1개로 센다. (동일 쌍은 중복 계산하지 않는다.)
    • 각 항공기에 대해 구한 (plane_id, 충돌 횟수) 튜플을 리스트에 담아 반환한다.
    • 충돌 횟수가 0인 항공기는 결과 리스트에 포함하지 않는다.
    • 반환 값 : [(plane_id, conflict_count), ...] 형식의 리스트

2. 입력 형식
  - 1행: 정수 N (비행편 개수)
  - 2 ~ (N+1)행: plane_id start end 
    • plane_id: 문자열 (ex: A1, B737)
    • start: 정수 (출발 시각, 0 이상)
    • end: 정수 (도착 시각, start보다 커야함) 
  - 입력으로 주어진 비행편들은 시간 순서와 무관하게 섞여 있을 수 있다.

ex) 예시 입력
6
A1 1 4 
A2 3 5
A3 3 6 
A1 8 10
A2 5 7
A3 0 2

3. 출력 형식
  - 첫 줄에 "=== Flight Conflicts ===" 문자열을 출력한다.
  - count_conflicts(flights)의 결과 리스를 받아, 항목이 하나도 없다면 "None"을 출력
  - 항목이 하나 이상이면, 각 항공기에 대해 한 줄씩 다음 형식으로 출력한다.
plane_id conflict_count

ex) 예시 출력
=== Flight Conflicts ===
A1 1

-------------------------------------------------------------------------------------------------------------------------
예시 입력 2
8
A1 0 5
A1 2 4
A1 4 8
A1 8 10
A2 1 3
A2 2 5
A2 6 9
A3 0 2

예시 출력 2
=== Flight Conflicts ===
A1 2
A2 1
'''

'''
• 매개변수: 네 개의 정수 (출발 시간1, 도착 시간1, 출발 시간2, 도착 시간2)
• 두 구간 [start1, end1)과 [start2, end2)가 시간적으로 겹치면 True를, 
  겹치지 않으면 False를 반환한다.
• 단, 한 비행의 도착 시간과 다른 비행의 출발 시간이 정확히 같은 경우 
  겹치지 않는 것으로 간주한다.
    ex) [1, 3)와 [3, 5)는 False
'''
def is_overlap(start1, end1, start2, end2):
    dur1 = []
    dur2 = []
    # dur1과 dur2에 각각 s1-e1, s2-e2가 점유하는 시간을 정수로 입력,
    # 두 list랑 비교할 때, 중첩값이 있으면 오류반환
    if end1 == start2:
        start2 += 1 
        # 앞 비행기의 점유시간 끝, 뒷 비행기의 점유시작시간이 같다면,
        # 비교를 위해 뒷 비행기의 점유시작시간을 1 미룸.
    for i in range(end1 - start1 + 1):
        dur1.append(i + start1)
        # print("dur1",dur1)
    for i in range(end2 - start2 + 1):
        dur2.append(i + start2)
        # print("dur2:",dur2)
    

    # --- 반환 --- #
    # 1. 완전 같은 경우
    if dur1 == dur2:
        return False
    
    # 2. 하나라도 겹치는 경우
    for i in dur1:
        if i in dur2:
            return True
    
    # 3. 하나도 안 겹치는 경우
    return False
        
    

'''
• flights: [(plane_id, start_time, end_time), ...] 튜플을 인자로 하는 리스트
• 같은 plane_id를 가진 비행편들 중 시간이 겹치는 비행평의 개수를 센다.
• 한 항공기에 대해 두 비행편이 겹치면 충돌 1개로 센다. (동일 쌍은 중복 계산하지 않는다.)
• 각 항공기에 대해 구한 (plane_id, 충돌 횟수) 튜플을 리스트에 담아 반환한다.
• 충돌 횟수가 0인 항공기는 결과 리스트에 포함하지 않는다.
• 반환 값 : [(plane_id, conflict_count), ...] 형식의 리스트
'''

def count_conflicts(flights):
    lenght = len(flights)
    result = []
    ischked = [] # 충돌 검증이 된 항목의 idx는 int로 저장
    isconplicted = 0 # 항공편의 시간 충돌 횟수를 저장함.
    for i in range(lenght):
        # print(f"{flights[i][0]}, {isconplicted}")
        isconplicted = 0 # 충돌 횟수 초기화

        if i in ischked: # 검증이 끝난 비행기는 확인 할 필요 없음
            continue
        for j in range(i + 1, lenght):
            # 같은 비행기에 대한 두개 이상의 항공편이 존재하면 비교 시작
            if flights[i][0] ==  flights[j][0]:
                
                # a랑 b 항공편이 겹치면
                if is_overlap(flights[i][1], flights[i][2],
                              flights[j][1], flights[j][2]):
                    ischked.append(j) # 비교한 대상의 idx 저장
                    isconplicted += 1
        
        if isconplicted > 0 : # 충돌 횟수가 있으면 tuple로 추가
            result.append((flights[i][0], isconplicted))
            
        
    return result

# --- 입력 --- #
n = int(input()) # 총 비행편 수

uncleared_flights = [] # 비교 전 항공편들 저장

for i in range(n): # 비행기 이름, 시작, 끝 입력
    Airplane, start_time, end_time = input().split()
    start_time = int(start_time)
    end_time = int(end_time)
    uncleared_flights.append((Airplane, start_time, end_time))
    # print(uncleared_flights)

cleared_flights = count_conflicts(uncleared_flights)


# --- 출력 --- #
print("=== Flight Conflicts ===")
for i in range(len(cleared_flights)):
    if cleared_flights == []:
        print("None")
        break
    print(f"{cleared_flights[i][0]} {cleared_flights[i][1]}")


# print(is_overlap(1,3,3,5))
