def testRepeated(func,tests):
    for item in range(len(tests)):
        if func(tests[item][0]) != tests[item][1]:
            print("Does not work - Test# " + str(item+1))
            return
    print("Tests Passed")
