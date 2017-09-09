;; Auto-generated. Do not edit!


(when (boundp 'atom_esp_listener::Profiler_data)
  (if (not (find-package "ATOM_ESP_LISTENER"))
    (make-package "ATOM_ESP_LISTENER"))
  (shadow 'Profiler_data (find-package "ATOM_ESP_LISTENER")))
(unless (find-package "ATOM_ESP_LISTENER::PROFILER_DATA")
  (make-package "ATOM_ESP_LISTENER::PROFILER_DATA"))

(in-package "ROS")
;;//! \htmlinclude Profiler_data.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass atom_esp_listener::Profiler_data
  :super ros::object
  :slots (_header _timestamp _averageIterationCount _averageTime _averageTime2 _averageTick ))

(defmethod atom_esp_listener::Profiler_data
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:timestamp __timestamp) 0)
    ((:averageIterationCount __averageIterationCount) 0)
    ((:averageTime __averageTime) 0.0)
    ((:averageTime2 __averageTime2) 0.0)
    ((:averageTick __averageTick) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _timestamp (round __timestamp))
   (setq _averageIterationCount (round __averageIterationCount))
   (setq _averageTime (float __averageTime))
   (setq _averageTime2 (float __averageTime2))
   (setq _averageTick (round __averageTick))
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
  (:averageIterationCount
   (&optional __averageIterationCount)
   (if __averageIterationCount (setq _averageIterationCount __averageIterationCount)) _averageIterationCount)
  (:averageTime
   (&optional __averageTime)
   (if __averageTime (setq _averageTime __averageTime)) _averageTime)
  (:averageTime2
   (&optional __averageTime2)
   (if __averageTime2 (setq _averageTime2 __averageTime2)) _averageTime2)
  (:averageTick
   (&optional __averageTick)
   (if __averageTick (setq _averageTick __averageTick)) _averageTick)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _timestamp
    4
    ;; uint16 _averageIterationCount
    2
    ;; float32 _averageTime
    4
    ;; float32 _averageTime2
    4
    ;; uint32 _averageTick
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _timestamp
       (write-long _timestamp s)
     ;; uint16 _averageIterationCount
       (write-word _averageIterationCount s)
     ;; float32 _averageTime
       (sys::poke _averageTime (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _averageTime2
       (sys::poke _averageTime2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _averageTick
       (write-long _averageTick s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _timestamp
     (setq _timestamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint16 _averageIterationCount
     (setq _averageIterationCount (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _averageTime
     (setq _averageTime (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _averageTime2
     (setq _averageTime2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _averageTick
     (setq _averageTick (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get atom_esp_listener::Profiler_data :md5sum-) "c31fa7394a8f9d53d1de6f6692e65a32")
(setf (get atom_esp_listener::Profiler_data :datatype-) "atom_esp_listener/Profiler_data")
(setf (get atom_esp_listener::Profiler_data :definition-)
      "Header  header
uint32  timestamp
uint16  averageIterationCount
float32 averageTime # micros
float32 averageTime2 # micros
uint32  averageTick

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



(provide :atom_esp_listener/Profiler_data "c31fa7394a8f9d53d1de6f6692e65a32")


