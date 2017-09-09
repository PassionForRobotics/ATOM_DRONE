; Auto-generated. Do not edit!


(cl:in-package atom_esp_listener-msg)


;//! \htmlinclude Profiler_data.msg.html

(cl:defclass <Profiler_data> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (timestamp
    :reader timestamp
    :initarg :timestamp
    :type cl:integer
    :initform 0)
   (averageIterationCount
    :reader averageIterationCount
    :initarg :averageIterationCount
    :type cl:fixnum
    :initform 0)
   (averageTime
    :reader averageTime
    :initarg :averageTime
    :type cl:float
    :initform 0.0)
   (averageTime2
    :reader averageTime2
    :initarg :averageTime2
    :type cl:float
    :initform 0.0)
   (averageTick
    :reader averageTick
    :initarg :averageTick
    :type cl:integer
    :initform 0))
)

(cl:defclass Profiler_data (<Profiler_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Profiler_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Profiler_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name atom_esp_listener-msg:<Profiler_data> is deprecated: use atom_esp_listener-msg:Profiler_data instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Profiler_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:header-val is deprecated.  Use atom_esp_listener-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'timestamp-val :lambda-list '(m))
(cl:defmethod timestamp-val ((m <Profiler_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:timestamp-val is deprecated.  Use atom_esp_listener-msg:timestamp instead.")
  (timestamp m))

(cl:ensure-generic-function 'averageIterationCount-val :lambda-list '(m))
(cl:defmethod averageIterationCount-val ((m <Profiler_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:averageIterationCount-val is deprecated.  Use atom_esp_listener-msg:averageIterationCount instead.")
  (averageIterationCount m))

(cl:ensure-generic-function 'averageTime-val :lambda-list '(m))
(cl:defmethod averageTime-val ((m <Profiler_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:averageTime-val is deprecated.  Use atom_esp_listener-msg:averageTime instead.")
  (averageTime m))

(cl:ensure-generic-function 'averageTime2-val :lambda-list '(m))
(cl:defmethod averageTime2-val ((m <Profiler_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:averageTime2-val is deprecated.  Use atom_esp_listener-msg:averageTime2 instead.")
  (averageTime2 m))

(cl:ensure-generic-function 'averageTick-val :lambda-list '(m))
(cl:defmethod averageTick-val ((m <Profiler_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:averageTick-val is deprecated.  Use atom_esp_listener-msg:averageTick instead.")
  (averageTick m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Profiler_data>) ostream)
  "Serializes a message object of type '<Profiler_data>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'averageIterationCount)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'averageIterationCount)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'averageTime))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'averageTime2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'averageTick)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'averageTick)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'averageTick)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'averageTick)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Profiler_data>) istream)
  "Deserializes a message object of type '<Profiler_data>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'averageIterationCount)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'averageIterationCount)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'averageTime) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'averageTime2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'averageTick)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'averageTick)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'averageTick)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'averageTick)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Profiler_data>)))
  "Returns string type for a message object of type '<Profiler_data>"
  "atom_esp_listener/Profiler_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Profiler_data)))
  "Returns string type for a message object of type 'Profiler_data"
  "atom_esp_listener/Profiler_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Profiler_data>)))
  "Returns md5sum for a message object of type '<Profiler_data>"
  "c31fa7394a8f9d53d1de6f6692e65a32")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Profiler_data)))
  "Returns md5sum for a message object of type 'Profiler_data"
  "c31fa7394a8f9d53d1de6f6692e65a32")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Profiler_data>)))
  "Returns full string definition for message of type '<Profiler_data>"
  (cl:format cl:nil "Header  header~%uint32  timestamp~%uint16  averageIterationCount~%float32 averageTime # micros~%float32 averageTime2 # micros~%uint32  averageTick~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Profiler_data)))
  "Returns full string definition for message of type 'Profiler_data"
  (cl:format cl:nil "Header  header~%uint32  timestamp~%uint16  averageIterationCount~%float32 averageTime # micros~%float32 averageTime2 # micros~%uint32  averageTick~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Profiler_data>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     2
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Profiler_data>))
  "Converts a ROS message object to a list"
  (cl:list 'Profiler_data
    (cl:cons ':header (header msg))
    (cl:cons ':timestamp (timestamp msg))
    (cl:cons ':averageIterationCount (averageIterationCount msg))
    (cl:cons ':averageTime (averageTime msg))
    (cl:cons ':averageTime2 (averageTime2 msg))
    (cl:cons ':averageTick (averageTick msg))
))
