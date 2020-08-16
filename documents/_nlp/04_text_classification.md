---
 title: 04_text_classification
 categories: nlp
 tags: nlp
 date: 2020-06-19
---

## refer

![corpus-google drive](https://drive.google.com/drive/u/0/folders/0Bz8a_Dbh9Qhbfll6bVpmNUtUcFdjYmF2SEpmZUZUcVNiMUw1TWN6RDV3a0JHT3kxLVhVR2M)

## Text classification in general

![text_c1](imgs/text_c1.png)

label kinds:
- Discrete labels:
    - Label is known:
        - Binary classification: spam filtering/sentiment analysis
        - Multi-class classification: categorization of goods
        - Multi-label classification: #hashtag prediction
    - Label is unknown:
i. Text clasterization: user intent search
- Continuous labels: predict a salary by CV, predict a price by a product description

Some common classification algorithms:
- Maximum Entropy Method = sklearn.linear_model.LogisticRegression
- Multinomial Naive Bayes = sklearn.naive_bayes.MultinomialNB

text representation: feature engineering

## NBOW

Instead of sparse one-hot encoding we can use pretrained word embedding, which is so-called "Neural Bag-Of-Words".