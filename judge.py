with open('../Working/io/correct.txt', 'r') as correctFile:
    correct = correctFile.read().rstrip()

with open('../Working/io/output.txt', 'r') as outputFile:
    output = outputFile.read().rstrip()

print('Success' if correct == output else 'Failed')
