# Markov-Chain-Generator
### Description
---------------
A C++ static library for generating Markov Chain text output

The Markov Chain is created from a source input text, and can produce varying levels of "randomness" in the output.
The lower the prefix size, the more random the output (can produce seemingly garbage incomprehensible text).
The larger the prefix size, the more structured of an output generated (too large and you will get a straight quotation of the input text)
   
### What is a Markov Chain?
---------------------------
A Markov Chain is a stochastic process in which the conditional probability distribution of future states of the process depends only upon the present state, not on the sequence of events that preceded it. [Wikipedia](https://en.wikipedia.org/wiki/Markov_chain)

A Markov Chain tells you the probability of transitioning from one state to another based only on the current state of the Markov Chain.

An effective use of this is text generation of varying degrees of randomness, based off some input text.

[Explained Visually](http://setosa.io/ev/markov-chains/) has a great explanation on how they work

### Example output
------------------
Some sample output from running the generator on the full text of Alice in Wonderland
>>Alice was beginning to get in at once." And in she went. Once more she found she could see, when she went on growing and growing and growing sometimes taller and sometimes she scolded herself so severely as to size," Alice hastily replied, "only one doesn't like changing so often, you know. So you see, Miss, this here ought to tell me your history, you know," said Alice, "because I'm not looking for eggs, as it spoke. "As wet as ever," said Alice (she was so large a house that she remained the same thing, you know." "You might just as I used--and I don't take this child away with Alice. Alice heard the King said to herself, as she was dozing off, when suddenly, thump! thump! down she came upon a heap of sticks and dry leaves, and the blades of grass, but she heard a voice of thunder
