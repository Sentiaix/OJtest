'''PYTHON2025 2학기 컴공 
#소스코드 한글지원 안됩니다.

#----------------------------------------------------------------------------------------------------------------------------------------------------------
#문제: 기계 당 시간당 처리량을 바탕으로 전체 작업을 고려하였을 때 부하가 걸릴 수 있는 기계를 찾는 프로그램을 구현하시오. 아래의 지시사항을 따라 코드를 작성하시오. 

1. 함수 구현
  - get_capacity(machines, machine_name):
    • machines에서 해당 이름의 capacity(int) 반환, 없으면 None 반환
  - calculate_loads(machines, jobs):
    • 결과: [(machine_name, total_hours), ...] 리스트 반환
    • 한 작업의 시간 = quantity / capacity
    • 설비 별 모든 작업 시간 합을 total_hours로 계산
    • 작업이 없으면 total_hours = 0.0

2. 입력 형식
  - 1행: 정수 N (설비 개수)
  - 2 ~ (N+1)행: machine_name capacity 
    • machine_name: 문자열
    • capacity: 정수
  - 다음 줄: 정수 M (작업 개수)
  - 이후 행: oder_id product_name machine_name quantity
    • order_id, product_name, machnie_name: 문자열
    • quantity: 정수
ex) 예시 입력
3
A1 10
A2 5
A3 8
5
O1 P1 A1 50
O2 P2 A2 40
O3 P3 A3 32
O4 P4 A1 30
O5 P5 A2 15

3. 출력 형식
  - 설비별 작업 시간 (total_hours 큰 순, total_hours는 소수 둘째 자리까지)
    • "=== Machine Loads ===" 를 상단에 출력하시오
  - 과부하 설비 (일일 작업 시간이 8.0 시간 초과인 설비만)
    • "=== Overloaded Machines (over 8.0 h) ==="를 상단에 출력하시오
ex) 예시 출력
=== Machine Loads ===
A2 11.00 h
A1 8.00 h
A3 4.00 h
=== Overloaded Machines (over 8.0 h) ===
A2 11.00 h
'''


'''
1) 입력
    1. 기계이름 | 시간당 수용능력 입력 (n세트 입력)
    2. 주문번호 | 제품번호 | 할당할 기계 이름 | 수량 입력 (m세트 입력)

2) 주요로직
    1. 1)-2번에서 받은 (기계이름: 작업 수량)을 합산 처리 과정
    2. calculate_loads()함수에서 할당된 수용 능력을 순서대로 출력하고,
       과부화가 걸린 값 기계 출력.

'''

# 특정 기계의 수행능력(capacity)을 반환하는 함수
def get_capacity(machines, machine_name):
    if mac[machine_name] is not None:
        return mac[machine_name]
    else :
        return None
    
# 전체적으로 기계에 할당된 업무를 시간으로 출력하는 함수
def calculate_loads(machines, jobs):
    calced_orders = {}
    # 작업량 / 수용능력 정리해서 새 dict에 입력
    for key in machines_list:
        calced_orders[key] = orders[key] / mac[key]
        print(calced_orders)
    
    # 이렇게 하면 tuple로 return됨.
    calced_orders = sorted(calced_orders.items()
                           , key=lambda x: x[1])
    
    m = len(calced_orders)

    print("=== Machine Loads ===")
    for i in range(m):
        cMac_name = calced_orders[i][0]
        cMac_cap = calced_orders[i][1]
        print(f"{cMac_name} {cMac_cap:.2f} h")

    print("=== Overloaded Machines (over 8.0 h) ===")
    for m in calced_orders[0]:
        if calced_orders[m][1] > 8.00:
            print(f"{m} {calced_orders:.2f} h")


# --- 1번째 입력. 기계 정보 --- #
n = int(input()) # 기계 수 입력
mac = {} # 기계이름: 시간당 수용능력 저장

for i in range(n): # 기계의 수용능력 입력
    mac_name, machine = input().split()
    machine = int(machine)
    mac[mac_name] = machine

m = int(input()) # 작업 Case 수 입력


# --- 2번째 입력. 작업 할당 --- #
orders = {} # ('기계번호': 작업량)

for i in range(m):
    # order_id, product_name, mac_name, quantitiy(int)
    o, p, a, quan = input().split()
    quan = int(quan)

    # 주문번호, 제품번호를 무시하고 (기계번호: 작업량)만 dict로 저장
    if a in orders.keys(): # key is immutable, but value is mutable
        orders[a] += quan
    else :
        orders[a] = quan

machines_list = []
jobs_list = []
for k in orders.keys():
    machines_list.append(k)
    jobs_list.append(orders[k])

calculate_loads(machines_list, jobs_list)