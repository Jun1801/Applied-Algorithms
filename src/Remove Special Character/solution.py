import string
text = "Hello!!!, How ? are;you'' What 'if we** do &]not g'o o%^ut"

print(string.punctuation)
translator = str.maketrans('', '', string.punctuation)
clean_text = text.translate(translator)
print(clean_text)