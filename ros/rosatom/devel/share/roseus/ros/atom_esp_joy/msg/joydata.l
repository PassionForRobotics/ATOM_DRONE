;; Auto-generated. Do not edit!


(when (boundp 'atom_esp_joy::joydata)
  (if (not (find-package "ATOM_ESP_JOY"))
    (make-package "ATOM_ESP_JOY"))
  (shadow 'joydata (find-package "ATOM_ESP_JOY")))
(unless (find-package "ATOM_ESP_JOY::JOYDATA")
  (make-package "ATOM_ESP_JOY::JOYDATA"))

(in-package "ROS")
;;//! \htmlinclude joydata.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass atom_esp_joy::joydata
  :super ros::object
  :slots (_H _X _Y _Z _S _buttons ))

(defmethod atom_esp_joy::joydata
  (:init
   (&key
    ((:H __H) (instance std_msgs::Header :init))
    ((:X __X) 0)
    ((:Y __Y) 0)
    ((:Z __Z) 0)
    ((:S __S) 0)
    ((:buttons __buttons) 0)
    )
   (send-super :init)
   (setq _H __H)
   (setq _X (round __X))
   (setq _Y (round __Y))
   (setq _Z (round __Z))
   (setq _S (round __S))
   (setq _buttons (round __buttons))
   self)
  (:H
   (&rest __H)
   (if (keywordp (car __H))
       (send* _H __H)
     (progn
       (if __H (setq _H (car __H)))
       _H)))
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
    ;; std_msgs/Header _H
    (send _H :serialization-length)
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
     ;; std_msgs/Header _H
       (send _H :serialize s)
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
   ;; std_msgs/Header _H
     (send _H :deserialize buf ptr-) (incf ptr- (send _H :serialization-length))
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

(setf (get atom_esp_joy::joydata :md5sum-) "b9528701db416223921ea3eb84e581e7")
(setf (get atom_esp_joy::joydata :datatype-) "atom_esp_joy/joydata")
(setf (get atom_esp_joy::joydata :definition-)
      "Header H
int16 X
int16 Y
int16 Z
int16 S
uint16 buttons # MSB F1,B2,3,4,5,6,7,8,9,10,11,12,H1,2,3,4 LSB
# 0000 0
# 0001 1
# 0010 2
# 0011 3
# 0100 4
# 0101 5
# 0110 6
# 0111 7
# 1000 8

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :atom_esp_joy/joydata "b9528701db416223921ea3eb84e581e7")


