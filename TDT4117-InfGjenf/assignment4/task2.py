import nltk
import string
import numpy as np
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer

nltk.download("stopwords")
nltk.download("punkt")

stopwords = set(stopwords.words("english"))

def text_indexer(collection, stopwords):
    stemmer = PorterStemmer()
    document_tokens = [nltk.tokenize.word_tokenize(d) for d in collection]
    document_tokens = [[w.lower() for w in d if not w.lower() in stopwords and w.lower() not in string.punctuation] for d in document_tokens]
    document_tokens = [[stemmer.stem(token.strip(string.punctuation)) for token in d] for d in document_tokens]
    
    document_vocabulary = set([w for d in document_tokens for w in d])
    document_inverted_index = {}
    for word in document_vocabulary:
        document_inverted_index[word] = [[i + 1, len([w for w in d if w == word])] for i, d in enumerate(document_tokens) if word in d]
    
    return document_inverted_index

collection = []
for i in range(1,7):
    with open(f"DataAssignment4/Text{i}.txt", "r") as doc:
        collection.append(doc.read())

indexed_docs = text_indexer(collection, stopwords)

# for key, value in indexed_docs.items():
#     print(key, value)

def preprocess_query(query):
    stemmer = PorterStemmer()
    query = nltk.tokenize.word_tokenize(query)
    query = [w.lower() for w in query if not w.lower() in stopwords and w.lower() not in string.punctuation]
    query = [stemmer.stem(token.strip(string.punctuation)) for token in query]

    return query

def search(query):
    query = preprocess_query(query)
    hits = []
    res = []
    for word in query:
        for w in indexed_docs: 
            if w.startswith(word):
                hits.append(w)
    for x in hits:
        res += indexed_docs[x]
    return rank_result(res)

def rank_result(res: list[list[int]]):
    res.sort(key=lambda x: x[0], reverse=True)
    # combine all lists with the same x[0]
    for i in range(len(res)):
        for j in range(i+1, len(res)):
            if res[i][0] == res[j][0]:
                res[i][1] += res[j][1]
                res[j][1] = 0
    # remove all lists with x[1] = 0
    res = [x for x in res if x[1] != 0]
    return sorted(res, key=lambda x: x[1], reverse=True)

# print(rank_result(search("claims of duty")))

q1 = "claim"
print(f"Q1: {search(q1)}")

q2 = "claim*"
print(f"Q2: {search(q2)}")

q3 = "claims of duty"
print(f"Q3: {search(q3)}")


