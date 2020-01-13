(load-file "1_newton_square.el")

;;;------------------------------------------------------------
;;; 1.6
;;;------------------------------------------------------------
(defun thief-if (condition then-clause else-clause)
  (insert "i")
  (cond (condition then-clause)
	(t else-clause)))

(thief-if (= 2 3) 1 2)i
(thief-if (= 1 2) (insert "1") (insert "2"))12i

;;;------------------------------------------------------------
;;; 1.7
;;;------------------------------------------------------------

(defun good-enough? (old-guess new-guess)
  (< (abs (/  (- old-guess new-guess) old-guess)) 0.01))

(defun sqrt-iter (guess x)
  "get square root of x"
  (if (good-enough? guess (improve guess x))
      guess
    (sqrt-iter (improve guess x) x)))


(sqrt 0.0000000009)
(sqrt 900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)


;;;------------------------------------------------------------
;;; 1.8
;;;------------------------------------------------------------

(defun cube-good-enough? (old-guess new-guess)
  (< (abs (/  (- old-guess new-guess) old-guess)) 0.01))

(defun cube-iter (guess x)
  "get square root of x"
  (if (cube-good-enough? guess (cube-improve guess x))
      guess
    (cube-iter (cube-improve guess x) x)))
(defun cube-improve (guess x)
  (/ (+ (/ x (square guess)) (* guess 2)) 3))

(defun cube-root (x)
  (cube-iter 1.0 x))

(cube-root 27)
(cube-root 900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)

