import nltk
import string
import numpy as np
from nltk.corpus import stopwords

nltk.download("stopwords")
nltk.download("punkt")

# Ex. a)

text = "Intelligent behavior in people is a product of the mind. But the mind itself is more like what the human brain does."
stopwords = set(stopwords.words("english"))
text_tokens = nltk.tokenize.word_tokenize(text)
filtered_text = [w.lower() for w in text_tokens if not w.lower() in stopwords and w.lower() not in string.punctuation]

# print(filtered_text)

vocabulary = set(filtered_text)

inverted_index = {}

for word in vocabulary:
    inverted_index[word] = [1, len([w for w in filtered_text if w == word])]

# for key, value in inverted_index.items():
#     print(key, value)

# Ex. b

block_text = np.array_split(text_tokens, 5)
block_text = [" ".join(block) for block in block_text]

# for b in block_text:
#     print(b)

# print(block_text)

occurences = {}

for word in vocabulary:
    occurences[word] = [i + 1 for i, b in enumerate(block_text) if word in b.lower()]

# print(occurences)

# for key, value in occurences.items():
#     print(key, value)

# Ex. c

# print(sorted(text_tokens, key=len))
# print(sorted(list(set(list(text.lower())))))
# print(len(sorted(list(set(list(text.lower()))))))

# Ex. d
d1 = "Although we know much more about the human brain than we did even"
d2 = "ten years ago, the thinking it engages in remains pretty much a total"
d3 = "mystery. It is like a big jigsaw puzzle where we can see many of the"
d4 = "pieces, but cannot yet put them together. There is so much about us"
d5 = "that we do not understand at all."
documents = [d1, d2, d3, d4, d5]

document_tokens = [nltk.tokenize.word_tokenize(d) for d in documents]
document_tokens = [[w.lower() for w in d if not w.lower() in stopwords and w.lower() not in string.punctuation] for d in document_tokens]

document_vocabulary = set([w for d in document_tokens for w in d])

document_inverted_index = {}

for word in document_vocabulary:
    document_inverted_index[word] = [[i + 1, len([w for w in d if w == word])] for i, d in enumerate(document_tokens) if word in d]

# for key, value in document_inverted_index.items():
#     print(key, value)