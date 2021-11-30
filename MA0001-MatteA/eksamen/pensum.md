---
title: En lat students guide til MA0001
author: av Håvard Solberg Nybøe
date: Sist oppdatert - \today
geometry: margin=25mm
---

\tableofcontents

# Pensum

Under er en oversikt over pensum for MA0001 høsten 2021.

| Tema                                              | Kapittel                |
| ------------------------------------------------- | ----------------------- |
| Introduction                                      | Chapters 1.1.1 - 1.1.4  |
| Exponentials & Logarithms                         | Chapter 1.1.5           |
| Functions                                         | Chapter 1.2             |
| Inverse Functions                                 | Chapter 1.2.6           |
| Limits                                            | Chapters 3.1, 3.3       |
| Continuity                                        | Chapter 3.2             |
| Differentiation                                   | Chapters 4.1, 4.2, 4.3  |
| Taylor Polynommials                               | Chapter 7.6 (p.373-379) |
| Implicit Differentiation                          | Chapter 4.4.2           |
| L'Hospital's rule                                 | Chapters 5.5            |
| Extrema, Monotonicity & Graphs                    | Chapters 5.1, 5.2, 5.3  |
| Derivative of the Inverse Function                | Chapter 4.7.1           |
| Integration & The Fundamental Theorem of Calculus | Chapters 5.8, 6.1, 6.2  |
| Leibniz's Rule                                    | Chapter 6.2             |
| Integration with Substitution                     | Chapter 7.1             |
| Integration by Parts                              | Chapter 7.2             |
| Areas & Improper Integrals                        | Chapters 6.3.1, 7.4     |

# Disclaimer

Innholdet i dette dokumentet er hentet fra læreboka til MA0001. 
Dokumentet er kun laget for eget bruk.

Dokumentet ble originalt laget til mitt eget bruk som repetisjon til eksamen høsten 2021, 
men kan godt benyttes av andre late studenter som ikke gidder å lese til eksamen.
Jeg eier så og si ingen ting av innholdet i dokumentet da alt er ~~stjålet~~ hentet fra læreboka, emnesiden eller Wikipedia.

<!-- INTRODUCTION -->
\newpage
# Introduction

This section reviews some of the concepts and techniques from algebra and trigonometry that are frequently used in calculus.
The problems at the end of the section will help you reacquaint yourself with this material.

## The Real Numbers

The **real numbers** can most easily be visualized on the **real-number line**,
on which numbers are ordered so that if $a < b$ ,
then $a$ is to the left of $b$.
Sets (collections) of real numbers are typically denoted by the capital letters $A , B , C ,$ etc.
To describe the set A , we write
\begin{align*}
    A = \{x: condition\}
\end{align*}
where “condition” tells us which numbers are in the set A.
The most important sets in calculus are **intervals**.

The location of the number 0 on the real-number line is called the **origin**, and we
can measure the distance of the number x to the origin. For instance, − 5 is 5 units to
the left of the origin. A convenient notation for measuring distances from the origin
on the real-number line is the absolute value of a real number.

The absolute value of a real number $a$ , denoted by $|a|$ , is
\begin{align*}
|a| = \left\{ 
    \begin{array}{rl}
        a & \text{if } a \ge 0 \\
        -a & \text{if } a < 0 \\
    \end{array} \right.
\end{align*}

## Lines in the Plane

A **line** in the plane is a straight line that passes through two points.
A line is represented by the equation
\begin{align*}
    y = mx + b
\end{align*}
where $m$ is the slope of the line and $b$ is the y-intercept of the line.

## Equation of the Circle

A **circle** is the set of all points at a given distance, called the **radius**,
from a given point, called the **center**.
If $r$ is the distance from $(x_0 , y_0 )$ to $(x, y)$,
then, using the Pythagorean theorem, we find that
\begin{align*}
    r^2 = (x - x_0)^2 + (y - y_0)^2
\end{align*}
If $r = 1$ and $(x_0 , y_0 ) = ( 0 , 0 )$, the circle is called the **unit circle**.

## Trigonometry

To convert between degree and radian measure, we use the formula
\begin{align*}
    \text{rad}(a) = \frac{a}{180} \pi \\
    \text{deg}(a) = \frac{a}{\pi} 180
\end{align*}

where $a$ is the angle measured in degrees or radians.

There are four trigonometric functions that you should be familiar with: sine,
cosine, tangent, and secant; the other two, cotangent and cosecant, are rarely used.
The six are defined on a unit circle and are abbreviated as sin, cos,
tan, sec, cot, and csc, respectively. Recall that a positive angle is measured counter-clockwise 
from the positive x -axis, whereas a negative angle is measured clockwise.
The six trigonometric functions are defined as follows:
\begin{align*}
    \sin(a) = \frac{y}{1} \quad&\quad \csc(a) = \frac{1}{\sin(a)} \\
    \cos(a) = \frac{x}{1} \quad&\quad \sec(a) = \frac{1}{\cos(a)} \\
    \tan(a) = \frac{y}{x} \quad&\quad \cot(a) = \frac{1}{\tan(a)}
\end{align*}

There are a number of frequently used trigonometric identities. First, since
$\tan(\theta) = \frac{y}{x}$ with $y = \sin(θ)$ and $x = \cos(θ)$ , it follows that
\begin{align*}
    \tan(\theta) = \frac{\sin(\theta)}{\cos(\theta)}
\end{align*}

## Exponentials & Logarithms

An **exponential** is an expression of the form $$a^r$$
where $a$ is called the **base** and $r$ is called the **exponent**.

Unless r is an integer or unless r is a
rational number of the form p/q where p is an integer and q is an odd integer, we will
assume that a is positive. We summarize some of the properties of an exponential as
follows:
\begin{align*}
    a^r \cdot a^5 = a^{r + 5} \quad&\quad (ab)^r = a^{r} \cdot b^{r} \\
    \frac{a^r}{a^5} = a^{r - 5} \quad&\quad \left(\frac{a}{b}\right)^r = \frac{a^{r}}{b^{r}} \\
    a^{-r} = \frac{1}{a^r} \quad&\quad (a^{-r})^5 = a^{r\cdot5}
\end{align*}

A **logarithm** is the inverse function to the exponential and is expressed in the form $$\log_b(a)$$
where $b$ is called the **base** and $a$ is called the **argument**. 

The logarithm of a **product** is the sum of the logarithms of the numbers being multiplied; 
the logarithm of the **ratio of two numbers** is the difference of the logarithms. 
The logarithm of the **p-th power** of a number is p times the logarithm of the number itself; 
the logarithm of a **p-th root** is the logarithm of the number divided by p. 
The following table lists these identities with examples
\begin{align*}
    \log_b(xy) &= \log_b(x) + \log_b(y) \\
    \log_b\left(\frac{x}{y}\right) &= \log_b(x) - \log_b(y) \\
    \log_b(x^p) &= p \log_b(x) \\
    \log_b\left(\sqrt[p]{x}\right) &= \frac{\log_b(x)}{p}
\end{align*}

<!-- FUNCTIONS -->
\newpage
# Functions

## What Is a Function?
A **function** $f$ is a rule that assigns each element $x$ in the set $A$
exactly one element $y$ in the set $B$ . The element y is called the **image** (or **value**)
of $x$ under $f$ and is denoted by $f(x)$ (read “$f$ of $x$”). The set $A$ is called the
**domain** of $f$, the set $B$ is called the **codomain** of $f$, and the set $f(A) = \{y :y = f (x)$
for some $x ∈ A\}$ is called the **range** of $f$.

To define a function, we use the notation
\begin{align*}
    f : A &\rightarrow B \\
    x &\rightarrow f(x)
\end{align*}
where $A$ and $B$ are subsets of the set of real numbers. Frequently, we simply write
$y = f (x)$ and call $x$ the **independent** variable and $y$ the **dependent** variable.

## Polynomial Functions
Polynomial functions are the simplest elementary functions.
A **polynomial** function is a function of the form $$f(x) = a_0 + a_1x + a_2x^2 + \cdots + a_nx^n$$
where $n$ is a nonnegative integer and $a_0 , a_1 , \cdots , a_n$ are (real-valued) constants
with $a_n \neq 0$. The coefficient $a_n$ is called the **leading coefficient**, and $n$ is called
the **degree** of the polynomial function. The largest possible domain of $f$ is $\mathbb{R}$.

## Rational Functions
Rational functions are built from polynomial functions.
A **rational** function is the quotient of two polynomial functions
$p(x)$ and $q(x)$: 
\begin{align*}
    f(x) = \frac{p(x)}{q(x)} \quad\text{ for } q(x) \neq 0
\end{align*}
Since division by 0 is not allowed, we must exclude those values of $x$ for which $q(x) = 0$.

## Power Functions
A **power** function is of the form
\begin{align*}
    f(x) = x^r
\end{align*}
where $r$ is a real number.

## Exponential Functions
The function $f$ is an **exponential** function with base $a$ if
\begin{align*}
    f(x) = a^x
\end{align*}
where $a$ is a positive constant other than 1. The largest possible domain of $f$
is $\mathbb{R}$.
\newpage

## Inverse Functions
The inverse of a function $f$ reverses the effect
of $f$. That is, if $f$ maps $x$ into $y = f (x)$, then the inverse function, denoted by $f^{− 1}$
(read “$f$ inverse”), takes $y$ and maps it back into $x$.

Functions that have the property $x_1 \neq x_2 \text{ implies } f(x_1 ) \neq f (x_2 )$ or,
equivalently, $f(x_1 ) = f(x_2 ) \text{ implies } x_1 = x_2$ are called **one to one**. If you know
what the graph of a particular function looks like over its domain, then it is easy to
determine whether or not the function is one to one: If no horizontal line intersects
the graph of the function $f$ more than once, then $f$ is one to one. This criterion is
called the horizontal line test.

Let $f : A → B$ be a one-to-one function with range $f(A)$. The
**inverse** function $f^{−1}$ has domain $f(A)$ and range $A$ and is defined by
\begin{align*}
    f^{−1}(y) = x \quad\text{ if and only if } y = f(x)
\end{align*}
for all $y \in f(A)$.

## Logarithmic Functions
The inverse of $f(x) = a^x$ is called the \textbf{logarithm to base \textit{a}} and is
written $f^{− 1}(x) = \log_a(x)$.
The maximum domain of $f(x) = a^x$ is the set of all real numbers, and its range is the
set of all positive numbers. Since the range of $f$ is the domain of $f^{− 1}$ , we find that
the maximum domain of $f^{− 1}(x) = \log_a(x)$ is the set of positive numbers.

## Trigonometric Functions
The trigonometric functions are examples of periodic functions.
A function $f(x)$ is **periodic** if there is a positive constant $a$ such
that
\begin{align*}
    f(x + a) = f(x)
\end{align*}
for all $x$ in the domain of $f$. If $a$ is the smallest number with this property, we
call it the **period** of $f(x)$.

<!-- LIMITS -->
\newpage
# Limits & Continuity

## Limits

### What is a Limit?

### Limit Laws

## Continuity

### What Is Continuity?

### Combinations of Continuous Functions

## Limits at Infinity

<!-- DIFFERENTIATION -->

# Differentiation

<!-- TAYLOR POLYNOMIALS -->

# Taylor Polynommials

<!-- IMPLICIT DIFFERENTIATION -->

# Implicit Differentiation

<!-- L'HOSPITAL'S RULE -->

# L'Hospital's rule

<!-- EXTREMA, MONOTONICITY & GRAPHS -->

# Extrema, Monotonicity & Graphs

<!-- DERIVATIVE OF THE INVERSE FUNCTION -->

# Derivative of the Inverse Function

<!-- INTEGRATION & THE FOUNDATION THEOREM OF CALCULUS -->

# Integration & The Fundamental Theorem of Calculus

<!-- LEIBNIZ'S RULE -->

# Leibniz's Rule

<!-- INTEGRATION WITH SUBSTITUTION -->

# Integration with Substitution

<!-- INTEGRATION BY PARTS -->

# Integration by Parts

<!-- AREAS & IMPROPER INTEGRALS -->

# Areas & Improper Integrals
