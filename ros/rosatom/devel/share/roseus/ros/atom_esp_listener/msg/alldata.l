;; Auto-generated. Do not edit!


(when (boundp 'atom_esp_listener::alldata)
  (if (not (find-package "ATOM_ESP_LISTENER"))
    (make-package "ATOM_ESP_LISTENER"))
  (shadow 'alldata (find-package "ATOM_ESP_LISTENER")))
(unless (find-package "ATOM_ESP_LISTENER::ALLDATA")
  (make-package "ATOM_ESP_LISTENER::ALLDATA"))

(in-package "ROS")
;;//! \htmlinclude alldata.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass atom_esp_listener::alldata
  :super ros::object
  :slots (_header _mpuRAW _pingheight _ppfb _pplr _ppud _yaw _pitch _roll _timestamp _tune_type _profiled_loop _profiled_mpu _profiled_wifi _profiled_steer ))

(defmethod atom_esp_listener::alldata
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:mpuRAW __mpuRAW) (instance atom_esp_listener::mpudata :init))
    ((:pingheight __pingheight) 0.0)
    ((:ppfb __ppfb) (instance atom_esp_listener::PID_Tune_Params :init))
    ((:pplr __pplr) (instance atom_esp_listener::PID_Tune_Params :init))
    ((:ppud __ppud) (instance atom_esp_listener::PID_Tune_Params :init))
    ((:yaw __yaw) 0.0)
    ((:pitch __pitch) 0.0)
    ((:roll __roll) 0.0)
    ((:timestamp __timestamp) 0)
    ((:tune_type __tune_type) 0)
    ((:profiled_loop __profiled_loop) (instance atom_esp_listener::Profiler_data :init))
    ((:profiled_mpu __profiled_mpu) (instance atom_esp_listener::Profiler_data :init))
    ((:profiled_wifi __profiled_wifi) (instance atom_esp_listener::Profiler_data :init))
    ((:profiled_steer __profiled_steer) (instance atom_esp_listener::Profiler_data :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _mpuRAW __mpuRAW)
   (setq _pingheight (float __pingheight))
   (setq _ppfb __ppfb)
   (setq _pplr __pplr)
   (setq _ppud __ppud)
   (setq _yaw (float __yaw))
   (setq _pitch (float __pitch))
   (setq _roll (float __roll))
   (setq _timestamp (round __timestamp))
   (setq _tune_type (round __tune_type))
   (setq _profiled_loop __profiled_loop)
   (setq _profiled_mpu __profiled_mpu)
   (setq _profiled_wifi __profiled_wifi)
   (setq _profiled_steer __profiled_steer)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:mpuRAW
   (&rest __mpuRAW)
   (if (keywordp (car __mpuRAW))
       (send* _mpuRAW __mpuRAW)
     (progn
       (if __mpuRAW (setq _mpuRAW (car __mpuRAW)))
       _mpuRAW)))
  (:pingheight
   (&optional __pingheight)
   (if __pingheight (setq _pingheight __pingheight)) _pingheight)
  (:ppfb
   (&rest __ppfb)
   (if (keywordp (car __ppfb))
       (send* _ppfb __ppfb)
     (progn
       (if __ppfb (setq _ppfb (car __ppfb)))
       _ppfb)))
  (:pplr
   (&rest __pplr)
   (if (keywordp (car __pplr))
       (send* _pplr __pplr)
     (progn
       (if __pplr (setq _pplr (car __pplr)))
       _pplr)))
  (:ppud
   (&rest __ppud)
   (if (keywordp (car __ppud))
       (send* _ppud __ppud)
     (progn
       (if __ppud (setq _ppud (car __ppud)))
       _ppud)))
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:timestamp
   (&optional __timestamp)
   (if __timestamp (setq _timestamp __timestamp)) _timestamp)
  (:tune_type
   (&optional __tune_type)
   (if __tune_type (setq _tune_type __tune_type)) _tune_type)
  (:profiled_loop
   (&rest __profiled_loop)
   (if (keywordp (car __profiled_loop))
       (send* _profiled_loop __profiled_loop)
     (progn
       (if __profiled_loop (setq _profiled_loop (car __profiled_loop)))
       _profiled_loop)))
  (:profiled_mpu
   (&rest __profiled_mpu)
   (if (keywordp (car __profiled_mpu))
       (send* _profiled_mpu __profiled_mpu)
     (progn
       (if __profiled_mpu (setq _profiled_mpu (car __profiled_mpu)))
       _profiled_mpu)))
  (:profiled_wifi
   (&rest __profiled_wifi)
   (if (keywordp (car __profiled_wifi))
       (send* _profiled_wifi __profiled_wifi)
     (progn
       (if __profiled_wifi (setq _profiled_wifi (car __profiled_wifi)))
       _profiled_wifi)))
  (:profiled_steer
   (&rest __profiled_steer)
   (if (keywordp (car __profiled_steer))
       (send* _profiled_steer __profiled_steer)
     (progn
       (if __profiled_steer (setq _profiled_steer (car __profiled_steer)))
       _profiled_steer)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; atom_esp_listener/mpudata _mpuRAW
    (send _mpuRAW :serialization-length)
    ;; float32 _pingheight
    4
    ;; atom_esp_listener/PID_Tune_Params _ppfb
    (send _ppfb :serialization-length)
    ;; atom_esp_listener/PID_Tune_Params _pplr
    (send _pplr :serialization-length)
    ;; atom_esp_listener/PID_Tune_Params _ppud
    (send _ppud :serialization-length)
    ;; float32 _yaw
    4
    ;; float32 _pitch
    4
    ;; float32 _roll
    4
    ;; uint32 _timestamp
    4
    ;; uint16 _tune_type
    2
    ;; atom_esp_listener/Profiler_data _profiled_loop
    (send _profiled_loop :serialization-length)
    ;; atom_esp_listener/Profiler_data _profiled_mpu
    (send _profiled_mpu :serialization-length)
    ;; atom_esp_listener/Profiler_data _profiled_wifi
    (send _profiled_wifi :serialization-length)
    ;; atom_esp_listener/Profiler_data _profiled_steer
    (send _profiled_steer :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; atom_esp_listener/mpudata _mpuRAW
       (send _mpuRAW :serialize s)
     ;; float32 _pingheight
       (sys::poke _pingheight (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; atom_esp_listener/PID_Tune_Params _ppfb
       (send _ppfb :serialize s)
     ;; atom_esp_listener/PID_Tune_Params _pplr
       (send _pplr :serialize s)
     ;; atom_esp_listener/PID_Tune_Params _ppud
       (send _ppud :serialize s)
     ;; float32 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _timestamp
       (write-long _timestamp s)
     ;; uint16 _tune_type
       (write-word _tune_type s)
     ;; atom_esp_listener/Profiler_data _profiled_loop
       (send _profiled_loop :serialize s)
     ;; atom_esp_listener/Profiler_data _profiled_mpu
       (send _profiled_mpu :serialize s)
     ;; atom_esp_listener/Profiler_data _profiled_wifi
       (send _profiled_wifi :serialize s)
     ;; atom_esp_listener/Profiler_data _profiled_steer
       (send _profiled_steer :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; atom_esp_listener/mpudata _mpuRAW
     (send _mpuRAW :deserialize buf ptr-) (incf ptr- (send _mpuRAW :serialization-length))
   ;; float32 _pingheight
     (setq _pingheight (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; atom_esp_listener/PID_Tune_Params _ppfb
     (send _ppfb :deserialize buf ptr-) (incf ptr- (send _ppfb :serialization-length))
   ;; atom_esp_listener/PID_Tune_Params _pplr
     (send _pplr :deserialize buf ptr-) (incf ptr- (send _pplr :serialization-length))
   ;; atom_esp_listener/PID_Tune_Params _ppud
     (send _ppud :deserialize buf ptr-) (incf ptr- (send _ppud :serialization-length))
   ;; float32 _yaw
     (setq _yaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch
     (setq _pitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _roll
     (setq _roll (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _timestamp
     (setq _timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint16 _tune_type
     (setq _tune_type (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; atom_esp_listener/Profiler_data _profiled_loop
     (send _profiled_loop :deserialize buf ptr-) (incf ptr- (send _profiled_loop :serialization-length))
   ;; atom_esp_listener/Profiler_data _profiled_mpu
     (send _profiled_mpu :deserialize buf ptr-) (incf ptr- (send _profiled_mpu :serialization-length))
   ;; atom_esp_listener/Profiler_data _profiled_wifi
     (send _profiled_wifi :deserialize buf ptr-) (incf ptr- (send _profiled_wifi :serialization-length))
   ;; atom_esp_listener/Profiler_data _profiled_steer
     (send _profiled_steer :deserialize buf ptr-) (incf ptr- (send _profiled_steer :serialization-length))
   ;;
   self)
  )

(setf (get atom_esp_listener::alldata :md5sum-) "9f657d5dee01c22ca305fb4d2b9139bc")
(setf (get atom_esp_listener::alldata :datatype-) "atom_esp_listener/alldata")
(setf (get atom_esp_listener::alldata :definition-)
      "Header header
#int16  mpuData_AcX
#int16  mpuData_AcY
#int16  mpuData_AcZ
#uint32  mpuData_timestamp
#int16  mpuData_Tmp
#int16  mpuData_GyX
#int16  mpuData_GyY
#int16  mpuData_GyZ

mpudata mpuRAW
#int16  mpuRAW_AcX
#int16  mpuRAW_AcY
#int16  mpuRAW_AcZ
#uint32  mpuRAW_timestamp
#int16  mpuRAW_Tmp
#int16  mpuRAW_GyX
#int16  mpuRAW_GyY
#int16  mpuRAW_GyZ

float32  pingheight

PID_Tune_Params ppfb
#uint32  ppfb_timestamp
#float64  ppfb_Input
#float64  ppfb_Kd
#float64  ppfb_Ki
#float64  ppfb_Kp
#float64  ppfb_Output
#float64  ppfb_Setpoint

PID_Tune_Params pplr
#uint32  pplr_timestamp
#float64  pplr_Input
#float64  pplr_Kd
#float64  pplr_Ki
#float64  pplr_Kp
#float64  pplr_Output
#float64  pplr_Setpoint

PID_Tune_Params ppud
#uint32  ppud_timestamp
#float64  ppud_Input
#float64  ppud_Kd
#float64  ppud_Ki
#float64  ppud_Kp
#float64  ppud_Output
#float64  ppud_Setpoint

float32  yaw
float32  pitch
float32  roll

uint32  timestamp
uint16  tune_type

Profiler_data profiled_loop
Profiler_data profiled_mpu
Profiler_data profiled_wifi
Profiler_data profiled_steer



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

================================================================================
MSG: atom_esp_listener/mpudata
Header header
uint32 timestamp
int16  AcX
int16  AcY
int16  AcZ
int16  Tmp
int16  GyX
int16  GyY
int16  GyZ

================================================================================
MSG: atom_esp_listener/PID_Tune_Params
Header header
uint32  timestamp
float64 Setpoint
float64 Input
float64 Output
float64 Kd
float64 Ki
float64 Kp

================================================================================
MSG: atom_esp_listener/Profiler_data
Header  header
uint32  timestamp
uint16  averageIterationCount
float32 averageTime # micros
float32 averageTime2 # micros
uint32  averageTick

")



(provide :atom_esp_listener/alldata "9f657d5dee01c22ca305fb4d2b9139bc")


