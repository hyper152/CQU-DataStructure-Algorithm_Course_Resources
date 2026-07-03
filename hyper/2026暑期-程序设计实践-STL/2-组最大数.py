while True:
    try:
        n = int(input())
        nums = input().split()
        
        # 冒泡排序
        for i in range(n):
            for j in range(i + 1, n):
                # 如果 nums[j] + nums[i] > nums[i] + nums[j]，交换
                if nums[j] + nums[i] > nums[i] + nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]
        
        print(''.join(nums))
    except EOFError:
        break