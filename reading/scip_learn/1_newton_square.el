(defun sqrt-iter (guess x)
  "get square root of x"
  (if (good-enough? guess x)
      guess
    (sqrt-iter (improve guess x) x)))

(defun improve (guess x)
   (average guess (/ x guess)))

(defun average (x y)
  (/ (+ x y) 2))

(defun good-enough? (guess x)
  (< (abs (- (square guess) x)) 0.001))

(defun square (x)
  (* x x))

(defun sqrt (x)
  (sqrt-iter 1.0 x))

(sqrt 90)
(square (sqrt 91))

;;;(load-file "1_newton_square.el")
