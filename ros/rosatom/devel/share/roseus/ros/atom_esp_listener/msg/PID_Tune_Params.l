;; Auto-generated. Do not edit!


(when (boundp 'atom_esp_listener::PID_Tune_Params)
  (if (not (find-package "ATOM_ESP_LISTENER"))
    (make-package "ATOM_ESP_LISTENER"))
  (shadow 'PID_Tune_Params (find-package "ATOM_ESP_LISTENER")))
(unless (find-package "ATOM_ESP_LISTENER::PID_TUNE_PARAMS")
  (make-package "ATOM_ESP_LISTENER::PID_TUNE_PARAMS"))

(in-package "ROS")
;;//! \htmlinclude PID_Tune_Params.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass atom_esp_listener::PID_Tune_Params
  :super ros::object
  :slots (_header _timestamp _Setpoint _Input _Output _Kd _Ki _Kp ))

(defmethod atom_esp_listener::PID_Tune_Params
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:timestamp __timestamp) 0)
    ((:Setpoint __Setpoint) 0.0)
    ((:Input __Input) 0.0)
    ((:Output __Output) 0.0)
    ((:Kd __Kd) 0.0)
    ((:Ki __Ki) 0.0)
    ((:Kp __Kp) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _timestamp (round __timestamp))
   (setq _Setpoint (float __Setpoint))
   (setq _Input (float __Input))
   (setq _Output (float __Output))
   (setq _Kd (float __Kd))
   (setq _Ki (float __Ki))
   (setq _Kp (float __Kp))
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
  (:Setpoint
   (&optional __Setpoint)
   (if __Setpoint (setq _Setpoint __Setpoint)) _Setpoint)
  (:Input
   (&optional __Input)
   (if __Input (setq _Input __Input)) _Input)
  (:Output
   (&optional __Output)
   (if __Output (setq _Output __Output)) _Output)
  (:Kd
   (&optional __Kd)
   (if __Kd (setq _Kd __Kd)) _Kd)
  (:Ki
   (&optional __Ki)
   (if __Ki (setq _Ki __Ki)) _Ki)
  (:Kp
   (&optional __Kp)
   (if __Kp (setq _Kp __Kp)) _Kp)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _timestamp
    4
    ;; float64 _Setpoint
    8
    ;; float64 _Input
    8
    ;; float64 _Output
    8
    ;; float64 _Kd
    8
    ;; float64 _Ki
    8
    ;; float64 _Kp
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _timestamp
       (write-long _timestamp s)
     ;; float64 _Setpoint
       (sys::poke _Setpoint (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Input
       (sys::poke _Input (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Output
       (sys::poke _Output (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Kd
       (sys::poke _Kd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ki
       (sys::poke _Ki (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Kp
       (sys::poke _Kp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _timestamp
     (setq _timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _Setpoint
     (setq _Setpoint (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Input
     (setq _Input (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Output
     (setq _Output (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Kd
     (setq _Kd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ki
     (setq _Ki (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Kp
     (setq _Kp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get atom_esp_listener::PID_Tune_Params :md5sum-) "a7b9a3a1c6b3d0aceef163325064bf57")
(setf (get atom_esp_listener::PID_Tune_Params :datatype-) "atom_esp_listener/PID_Tune_Params")
(setf (get atom_esp_listener::PID_Tune_Params :definition-)
      "Header header
uint32  timestamp
float64 Setpoint
float64 Input
float64 Output
float64 Kd
float64 Ki
float64 Kp

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



(provide :atom_esp_listener/PID_Tune_Params "a7b9a3a1c6b3d0aceef163325064bf57")


