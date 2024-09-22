from datetime import datetime

def time_difference(start, end):
    time_format = "%H:%M:%S"
    start_time = datetime.strptime(start, time_format)
    end_time = datetime.strptime(end, time_format)
    # Calculate difference in seconds
    return int((end_time - start_time).total_seconds())

def determine_winner(time1, time2, x, y):
    if x > y:
        return "You"
    elif x < y:
        return "Lan"
    else:
        diff1 = time_difference(time1[0], time1[1])
        diff2 = time_difference(time2[0], time2[1])
        if diff1 > diff2:
            return "You"
        elif diff1 < diff2:
            return "Lan"
        else:
            return "Draw"
        
    all_time = x+y

def main():
    # Input parsing
    n = int(input())  # number of test cases
    
    for _ in range(n):
        time1_start, time1_end = input().split()
        time2_start, time2_end = input().split()
        x, y = map(int, input().split())
        
        # Get the winner for the current test case
        result = determine_winner((time1_start, time1_end), (time2_start, time2_end), x, y)
        
        # Print the result for the current test case
        print(result)

if __name__ == "__main__":
    main()