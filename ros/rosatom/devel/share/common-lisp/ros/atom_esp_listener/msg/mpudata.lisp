; Auto-generated. Do not edit!


(cl:in-package atom_esp_listener-msg)


;//! \htmlinclude mpudata.msg.html

(cl:defclass <mpudata> (roslisp-msg-protocol:ros-message)
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
   (AcX
    :reader AcX
    :initarg :AcX
    :type cl:fixnum
    :initform 0)
   (AcY
    :reader AcY
    :initarg :AcY
    :type cl:fixnum
    :initform 0)
   (AcZ
    :reader AcZ
    :initarg :AcZ
    :type cl:fixnum
    :initform 0)
   (Tmp
    :reader Tmp
    :initarg :Tmp
    :type cl:fixnum
    :initform 0)
   (GyX
    :reader GyX
    :initarg :GyX
    :type cl:fixnum
    :initform 0)
   (GyY
    :reader GyY
    :initarg :GyY
    :type cl:fixnum
    :initform 0)
   (GyZ
    :reader GyZ
    :initarg :GyZ
    :type cl:fixnum
    :initform 0))
)

(cl:defclass mpudata (<mpudata>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <mpudata>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'mpudata)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name atom_esp_listener-msg:<mpudata> is deprecated: use atom_esp_listener-msg:mpudata instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:header-val is deprecated.  Use atom_esp_listener-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'timestamp-val :lambda-list '(m))
(cl:defmethod timestamp-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:timestamp-val is deprecated.  Use atom_esp_listener-msg:timestamp instead.")
  (timestamp m))

(cl:ensure-generic-function 'AcX-val :lambda-list '(m))
(cl:defmethod AcX-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:AcX-val is deprecated.  Use atom_esp_listener-msg:AcX instead.")
  (AcX m))

(cl:ensure-generic-function 'AcY-val :lambda-list '(m))
(cl:defmethod AcY-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:AcY-val is deprecated.  Use atom_esp_listener-msg:AcY instead.")
  (AcY m))

(cl:ensure-generic-function 'AcZ-val :lambda-list '(m))
(cl:defmethod AcZ-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:AcZ-val is deprecated.  Use atom_esp_listener-msg:AcZ instead.")
  (AcZ m))

(cl:ensure-generic-function 'Tmp-val :lambda-list '(m))
(cl:defmethod Tmp-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:Tmp-val is deprecated.  Use atom_esp_listener-msg:Tmp instead.")
  (Tmp m))

(cl:ensure-generic-function 'GyX-val :lambda-list '(m))
(cl:defmethod GyX-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:GyX-val is deprecated.  Use atom_esp_listener-msg:GyX instead.")
  (GyX m))

(cl:ensure-generic-function 'GyY-val :lambda-list '(m))
(cl:defmethod GyY-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:GyY-val is deprecated.  Use atom_esp_listener-msg:GyY instead.")
  (GyY m))

(cl:ensure-generic-function 'GyZ-val :lambda-list '(m))
(cl:defmethod GyZ-val ((m <mpudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:GyZ-val is deprecated.  Use atom_esp_listener-msg:GyZ instead.")
  (GyZ m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <mpudata>) ostream)
  "Serializes a message object of type '<mpudata>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timestamp)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'AcX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'AcY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'AcZ)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Tmp)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'GyX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'GyY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'GyZ)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <mpudata>) istream)
  "Deserializes a message object of type '<mpudata>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'AcX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'AcY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'AcZ) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Tmp) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'GyX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'GyY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'GyZ) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<mpudata>)))
  "Returns string type for a message object of type '<mpudata>"
  "atom_esp_listener/mpudata")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'mpudata)))
  "Returns string type for a message object of type 'mpudata"
  "atom_esp_listener/mpudata")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<mpudata>)))
  "Returns md5sum for a message object of type '<mpudata>"
  "2da27b00d8c3d05a9b15d685c8870e9d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'mpudata)))
  "Returns md5sum for a message object of type 'mpudata"
  "2da27b00d8c3d05a9b15d685c8870e9d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<mpudata>)))
  "Returns full string definition for message of type '<mpudata>"
  (cl:format cl:nil "Header header~%uint32 timestamp~%int16  AcX~%int16  AcY~%int16  AcZ~%int16  Tmp~%int16  GyX~%int16  GyY~%int16  GyZ~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'mpudata)))
  "Returns full string definition for message of type 'mpudata"
  (cl:format cl:nil "Header header~%uint32 timestamp~%int16  AcX~%int16  AcY~%int16  AcZ~%int16  Tmp~%int16  GyX~%int16  GyY~%int16  GyZ~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <mpudata>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     2
     2
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <mpudata>))
  "Converts a ROS message object to a list"
  (cl:list 'mpudata
    (cl:cons ':header (header msg))
    (cl:cons ':timestamp (timestamp msg))
    (cl:cons ':AcX (AcX msg))
    (cl:cons ':AcY (AcY msg))
    (cl:cons ':AcZ (AcZ msg))
    (cl:cons ':Tmp (Tmp msg))
    (cl:cons ':GyX (GyX msg))
    (cl:cons ':GyY (GyY msg))
    (cl:cons ':GyZ (GyZ msg))
))
