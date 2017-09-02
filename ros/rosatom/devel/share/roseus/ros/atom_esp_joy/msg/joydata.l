;; Auto-generated. Do not edit!


(when (boundp 'atom_esp_joy::joydata)
  (if (not (find-package "ATOM_ESP_JOY"))
    (make-package "ATOM_ESP_JOY"))
  (shadow 'joydata (find-package "ATOM_ESP_JOY")))
(unless (find-package "ATOM_ESP_JOY::JOYDATA")
  (make-package "ATOM_ESP_JOY::JOYDATA"))

(in-package "ROS")
;;//! \htmlinclude joydata.msg.html


(defclass atom_esp_joy::joydata
  :super ros::object
  :slots (_X _Y _Z _S _buttons ))

(defmethod atom_esp_joy::joydata
  (:init
   (&key
    ((:X __X) 0)
    ((:Y __Y) 0)
    ((:Z __Z) 0)
    ((:S __S) 0)
    ((:buttons __buttons) 0)
    )
   (send-super :init)
   (setq _X (round __X))
   (setq _Y (round __Y))
   (setq _Z (round __Z))
   (setq _S (round __S))
   (setq _buttons (round __buttons))
   self)
  (:X
   (&optional __X)
   (if __X (setq _X __X)) _X)
  (:Y
   (&optional __Y)
   (if __Y (setq _Y __Y)) _Y)
  (:Z
   (&optional __Z)
   (if __Z (setq _Z __Z)) _Z)
  (:S
   (&optional __S)
   (if __S (setq _S __S)) _S)
  (:buttons
   (&optional __buttons)
   (if __buttons (setq _buttons __buttons)) _buttons)
  (:serialization-length
   ()
   (+
    ;; int16 _X
    2
    ;; int16 _Y
    2
    ;; int16 _Z
    2
    ;; int16 _S
    2
    ;; uint16 _buttons
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _X
       (write-word _X s)
     ;; int16 _Y
       (write-word _Y s)
     ;; int16 _Z
       (write-word _Z s)
     ;; int16 _S
       (write-word _S s)
     ;; uint16 _buttons
       (write-word _buttons s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _X
     (setq _X (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _Y
     (setq _Y (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _Z
     (setq _Z (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _S
     (setq _S (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _buttons
     (setq _buttons (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get atom_esp_joy::joydata :md5sum-) "9ea973d7e29e9a09bf4c38bea786a98f")
(setf (get atom_esp_joy::joydata :datatype-) "atom_esp_joy/joydata")
(setf (get atom_esp_joy::joydata :definition-)
      "int16 X
int16 Y
int16 Z
int16 S
uint16 buttons # F1,B2,3,4,5,6,7,8,9,10,11,12,H1,2,3,4
# 0000 0
# 0001 1
# 0010 2
# 0011 3
# 0100 4
# 0101 5
# 0110 6
# 0111 7
# 1000 8

")



(provide :atom_esp_joy/joydata "9ea973d7e29e9a09bf4c38bea786a98f")


