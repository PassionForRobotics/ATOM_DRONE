;; Auto-generated. Do not edit!


(when (boundp 'atom_esp_listener::mpudata)
  (if (not (find-package "ATOM_ESP_LISTENER"))
    (make-package "ATOM_ESP_LISTENER"))
  (shadow 'mpudata (find-package "ATOM_ESP_LISTENER")))
(unless (find-package "ATOM_ESP_LISTENER::MPUDATA")
  (make-package "ATOM_ESP_LISTENER::MPUDATA"))

(in-package "ROS")
;;//! \htmlinclude mpudata.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass atom_esp_listener::mpudata
  :super ros::object
  :slots (_header _timestamp _AcX _AcY _AcZ _Tmp _GyX _GyY _GyZ ))

(defmethod atom_esp_listener::mpudata
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:timestamp __timestamp) 0)
    ((:AcX __AcX) 0)
    ((:AcY __AcY) 0)
    ((:AcZ __AcZ) 0)
    ((:Tmp __Tmp) 0)
    ((:GyX __GyX) 0)
    ((:GyY __GyY) 0)
    ((:GyZ __GyZ) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _timestamp (round __timestamp))
   (setq _AcX (round __AcX))
   (setq _AcY (round __AcY))
   (setq _AcZ (round __AcZ))
   (setq _Tmp (round __Tmp))
   (setq _GyX (round __GyX))
   (setq _GyY (round __GyY))
   (setq _GyZ (round __GyZ))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:timestamp
   (&optional __timestamp)
   (if __timestamp (setq _timestamp __timestamp)) _timestamp)
  (:AcX
   (&optional __AcX)
   (if __AcX (setq _AcX __AcX)) _AcX)
  (:AcY
   (&optional __AcY)
   (if __AcY (setq _AcY __AcY)) _AcY)
  (:AcZ
   (&optional __AcZ)
   (if __AcZ (setq _AcZ __AcZ)) _AcZ)
  (:Tmp
   (&optional __Tmp)
   (if __Tmp (setq _Tmp __Tmp)) _Tmp)
  (:GyX
   (&optional __GyX)
   (if __GyX (setq _GyX __GyX)) _GyX)
  (:GyY
   (&optional __GyY)
   (if __GyY (setq _GyY __GyY)) _GyY)
  (:GyZ
   (&optional __GyZ)
   (if __GyZ (setq _GyZ __GyZ)) _GyZ)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _timestamp
    4
    ;; int16 _AcX
    2
    ;; int16 _AcY
    2
    ;; int16 _AcZ
    2
    ;; int16 _Tmp
    2
    ;; int16 _GyX
    2
    ;; int16 _GyY
    2
    ;; int16 _GyZ
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _timestamp
       (write-long _timestamp s)
     ;; int16 _AcX
       (write-word _AcX s)
     ;; int16 _AcY
       (write-word _AcY s)
     ;; int16 _AcZ
       (write-word _AcZ s)
     ;; int16 _Tmp
       (write-word _Tmp s)
     ;; int16 _GyX
       (write-word _GyX s)
     ;; int16 _GyY
       (write-word _GyY s)
     ;; int16 _GyZ
       (write-word _GyZ s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _timestamp
     (setq _timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int16 _AcX
     (setq _AcX (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _AcY
     (setq _AcY (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _AcZ
     (setq _AcZ (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _Tmp
     (setq _Tmp (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _GyX
     (setq _GyX (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _GyY
     (setq _GyY (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _GyZ
     (setq _GyZ (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get atom_esp_listener::mpudata :md5sum-) "2da27b00d8c3d05a9b15d685c8870e9d")
(setf (get atom_esp_listener::mpudata :datatype-) "atom_esp_listener/mpudata")
(setf (get atom_esp_listener::mpudata :definition-)
      "Header header
uint32 timestamp
int16  AcX
int16  AcY
int16  AcZ
int16  Tmp
int16  GyX
int16  GyY
int16  GyZ

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



(provide :atom_esp_listener/mpudata "2da27b00d8c3d05a9b15d685c8870e9d")


