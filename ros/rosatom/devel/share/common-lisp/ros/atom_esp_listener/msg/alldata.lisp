; Auto-generated. Do not edit!


(cl:in-package atom_esp_listener-msg)


;//! \htmlinclude alldata.msg.html

(cl:defclass <alldata> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (mpuData_AcX
    :reader mpuData_AcX
    :initarg :mpuData_AcX
    :type cl:fixnum
    :initform 0)
   (mpuData_AcY
    :reader mpuData_AcY
    :initarg :mpuData_AcY
    :type cl:fixnum
    :initform 0)
   (mpuData_AcZ
    :reader mpuData_AcZ
    :initarg :mpuData_AcZ
    :type cl:fixnum
    :initform 0)
   (mpuData_timestamp
    :reader mpuData_timestamp
    :initarg :mpuData_timestamp
    :type cl:integer
    :initform 0)
   (mpuData_Tmp
    :reader mpuData_Tmp
    :initarg :mpuData_Tmp
    :type cl:fixnum
    :initform 0)
   (mpuData_GyX
    :reader mpuData_GyX
    :initarg :mpuData_GyX
    :type cl:fixnum
    :initform 0)
   (mpuData_GyY
    :reader mpuData_GyY
    :initarg :mpuData_GyY
    :type cl:fixnum
    :initform 0)
   (mpuData_GyZ
    :reader mpuData_GyZ
    :initarg :mpuData_GyZ
    :type cl:fixnum
    :initform 0)
   (mpuRAW_AcX
    :reader mpuRAW_AcX
    :initarg :mpuRAW_AcX
    :type cl:fixnum
    :initform 0)
   (mpuRAW_AcY
    :reader mpuRAW_AcY
    :initarg :mpuRAW_AcY
    :type cl:fixnum
    :initform 0)
   (mpuRAW_AcZ
    :reader mpuRAW_AcZ
    :initarg :mpuRAW_AcZ
    :type cl:fixnum
    :initform 0)
   (mpuRAW_timestamp
    :reader mpuRAW_timestamp
    :initarg :mpuRAW_timestamp
    :type cl:integer
    :initform 0)
   (mpuRAW_Tmp
    :reader mpuRAW_Tmp
    :initarg :mpuRAW_Tmp
    :type cl:fixnum
    :initform 0)
   (mpuRAW_GyX
    :reader mpuRAW_GyX
    :initarg :mpuRAW_GyX
    :type cl:fixnum
    :initform 0)
   (mpuRAW_GyY
    :reader mpuRAW_GyY
    :initarg :mpuRAW_GyY
    :type cl:fixnum
    :initform 0)
   (mpuRAW_GyZ
    :reader mpuRAW_GyZ
    :initarg :mpuRAW_GyZ
    :type cl:fixnum
    :initform 0)
   (pingheight
    :reader pingheight
    :initarg :pingheight
    :type cl:float
    :initform 0.0)
   (ppfb_timestamp
    :reader ppfb_timestamp
    :initarg :ppfb_timestamp
    :type cl:integer
    :initform 0)
   (ppfb_Input
    :reader ppfb_Input
    :initarg :ppfb_Input
    :type cl:float
    :initform 0.0)
   (ppfb_Kd
    :reader ppfb_Kd
    :initarg :ppfb_Kd
    :type cl:float
    :initform 0.0)
   (ppfb_Ki
    :reader ppfb_Ki
    :initarg :ppfb_Ki
    :type cl:float
    :initform 0.0)
   (ppfb_Kp
    :reader ppfb_Kp
    :initarg :ppfb_Kp
    :type cl:float
    :initform 0.0)
   (ppfb_Output
    :reader ppfb_Output
    :initarg :ppfb_Output
    :type cl:float
    :initform 0.0)
   (ppfb_Setpoint
    :reader ppfb_Setpoint
    :initarg :ppfb_Setpoint
    :type cl:float
    :initform 0.0)
   (pplr_timestamp
    :reader pplr_timestamp
    :initarg :pplr_timestamp
    :type cl:integer
    :initform 0)
   (pplr_Input
    :reader pplr_Input
    :initarg :pplr_Input
    :type cl:float
    :initform 0.0)
   (pplr_Kd
    :reader pplr_Kd
    :initarg :pplr_Kd
    :type cl:float
    :initform 0.0)
   (pplr_Ki
    :reader pplr_Ki
    :initarg :pplr_Ki
    :type cl:float
    :initform 0.0)
   (pplr_Kp
    :reader pplr_Kp
    :initarg :pplr_Kp
    :type cl:float
    :initform 0.0)
   (pplr_Output
    :reader pplr_Output
    :initarg :pplr_Output
    :type cl:float
    :initform 0.0)
   (pplr_Setpoint
    :reader pplr_Setpoint
    :initarg :pplr_Setpoint
    :type cl:float
    :initform 0.0)
   (ppud_timestamp
    :reader ppud_timestamp
    :initarg :ppud_timestamp
    :type cl:integer
    :initform 0)
   (ppud_Input
    :reader ppud_Input
    :initarg :ppud_Input
    :type cl:float
    :initform 0.0)
   (ppud_Kd
    :reader ppud_Kd
    :initarg :ppud_Kd
    :type cl:float
    :initform 0.0)
   (ppud_Ki
    :reader ppud_Ki
    :initarg :ppud_Ki
    :type cl:float
    :initform 0.0)
   (ppud_Kp
    :reader ppud_Kp
    :initarg :ppud_Kp
    :type cl:float
    :initform 0.0)
   (ppud_Output
    :reader ppud_Output
    :initarg :ppud_Output
    :type cl:float
    :initform 0.0)
   (ppud_Setpoint
    :reader ppud_Setpoint
    :initarg :ppud_Setpoint
    :type cl:float
    :initform 0.0)
   (yaw
    :reader yaw
    :initarg :yaw
    :type cl:float
    :initform 0.0)
   (pitch
    :reader pitch
    :initarg :pitch
    :type cl:float
    :initform 0.0)
   (roll
    :reader roll
    :initarg :roll
    :type cl:float
    :initform 0.0)
   (timestamp
    :reader timestamp
    :initarg :timestamp
    :type cl:integer
    :initform 0)
   (tune_type
    :reader tune_type
    :initarg :tune_type
    :type cl:fixnum
    :initform 0))
)

(cl:defclass alldata (<alldata>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <alldata>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'alldata)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name atom_esp_listener-msg:<alldata> is deprecated: use atom_esp_listener-msg:alldata instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:header-val is deprecated.  Use atom_esp_listener-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'mpuData_AcX-val :lambda-list '(m))
(cl:defmethod mpuData_AcX-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuData_AcX-val is deprecated.  Use atom_esp_listener-msg:mpuData_AcX instead.")
  (mpuData_AcX m))

(cl:ensure-generic-function 'mpuData_AcY-val :lambda-list '(m))
(cl:defmethod mpuData_AcY-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuData_AcY-val is deprecated.  Use atom_esp_listener-msg:mpuData_AcY instead.")
  (mpuData_AcY m))

(cl:ensure-generic-function 'mpuData_AcZ-val :lambda-list '(m))
(cl:defmethod mpuData_AcZ-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuData_AcZ-val is deprecated.  Use atom_esp_listener-msg:mpuData_AcZ instead.")
  (mpuData_AcZ m))

(cl:ensure-generic-function 'mpuData_timestamp-val :lambda-list '(m))
(cl:defmethod mpuData_timestamp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuData_timestamp-val is deprecated.  Use atom_esp_listener-msg:mpuData_timestamp instead.")
  (mpuData_timestamp m))

(cl:ensure-generic-function 'mpuData_Tmp-val :lambda-list '(m))
(cl:defmethod mpuData_Tmp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuData_Tmp-val is deprecated.  Use atom_esp_listener-msg:mpuData_Tmp instead.")
  (mpuData_Tmp m))

(cl:ensure-generic-function 'mpuData_GyX-val :lambda-list '(m))
(cl:defmethod mpuData_GyX-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuData_GyX-val is deprecated.  Use atom_esp_listener-msg:mpuData_GyX instead.")
  (mpuData_GyX m))

(cl:ensure-generic-function 'mpuData_GyY-val :lambda-list '(m))
(cl:defmethod mpuData_GyY-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuData_GyY-val is deprecated.  Use atom_esp_listener-msg:mpuData_GyY instead.")
  (mpuData_GyY m))

(cl:ensure-generic-function 'mpuData_GyZ-val :lambda-list '(m))
(cl:defmethod mpuData_GyZ-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuData_GyZ-val is deprecated.  Use atom_esp_listener-msg:mpuData_GyZ instead.")
  (mpuData_GyZ m))

(cl:ensure-generic-function 'mpuRAW_AcX-val :lambda-list '(m))
(cl:defmethod mpuRAW_AcX-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW_AcX-val is deprecated.  Use atom_esp_listener-msg:mpuRAW_AcX instead.")
  (mpuRAW_AcX m))

(cl:ensure-generic-function 'mpuRAW_AcY-val :lambda-list '(m))
(cl:defmethod mpuRAW_AcY-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW_AcY-val is deprecated.  Use atom_esp_listener-msg:mpuRAW_AcY instead.")
  (mpuRAW_AcY m))

(cl:ensure-generic-function 'mpuRAW_AcZ-val :lambda-list '(m))
(cl:defmethod mpuRAW_AcZ-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW_AcZ-val is deprecated.  Use atom_esp_listener-msg:mpuRAW_AcZ instead.")
  (mpuRAW_AcZ m))

(cl:ensure-generic-function 'mpuRAW_timestamp-val :lambda-list '(m))
(cl:defmethod mpuRAW_timestamp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW_timestamp-val is deprecated.  Use atom_esp_listener-msg:mpuRAW_timestamp instead.")
  (mpuRAW_timestamp m))

(cl:ensure-generic-function 'mpuRAW_Tmp-val :lambda-list '(m))
(cl:defmethod mpuRAW_Tmp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW_Tmp-val is deprecated.  Use atom_esp_listener-msg:mpuRAW_Tmp instead.")
  (mpuRAW_Tmp m))

(cl:ensure-generic-function 'mpuRAW_GyX-val :lambda-list '(m))
(cl:defmethod mpuRAW_GyX-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW_GyX-val is deprecated.  Use atom_esp_listener-msg:mpuRAW_GyX instead.")
  (mpuRAW_GyX m))

(cl:ensure-generic-function 'mpuRAW_GyY-val :lambda-list '(m))
(cl:defmethod mpuRAW_GyY-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW_GyY-val is deprecated.  Use atom_esp_listener-msg:mpuRAW_GyY instead.")
  (mpuRAW_GyY m))

(cl:ensure-generic-function 'mpuRAW_GyZ-val :lambda-list '(m))
(cl:defmethod mpuRAW_GyZ-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:mpuRAW_GyZ-val is deprecated.  Use atom_esp_listener-msg:mpuRAW_GyZ instead.")
  (mpuRAW_GyZ m))

(cl:ensure-generic-function 'pingheight-val :lambda-list '(m))
(cl:defmethod pingheight-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pingheight-val is deprecated.  Use atom_esp_listener-msg:pingheight instead.")
  (pingheight m))

(cl:ensure-generic-function 'ppfb_timestamp-val :lambda-list '(m))
(cl:defmethod ppfb_timestamp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppfb_timestamp-val is deprecated.  Use atom_esp_listener-msg:ppfb_timestamp instead.")
  (ppfb_timestamp m))

(cl:ensure-generic-function 'ppfb_Input-val :lambda-list '(m))
(cl:defmethod ppfb_Input-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppfb_Input-val is deprecated.  Use atom_esp_listener-msg:ppfb_Input instead.")
  (ppfb_Input m))

(cl:ensure-generic-function 'ppfb_Kd-val :lambda-list '(m))
(cl:defmethod ppfb_Kd-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppfb_Kd-val is deprecated.  Use atom_esp_listener-msg:ppfb_Kd instead.")
  (ppfb_Kd m))

(cl:ensure-generic-function 'ppfb_Ki-val :lambda-list '(m))
(cl:defmethod ppfb_Ki-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppfb_Ki-val is deprecated.  Use atom_esp_listener-msg:ppfb_Ki instead.")
  (ppfb_Ki m))

(cl:ensure-generic-function 'ppfb_Kp-val :lambda-list '(m))
(cl:defmethod ppfb_Kp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppfb_Kp-val is deprecated.  Use atom_esp_listener-msg:ppfb_Kp instead.")
  (ppfb_Kp m))

(cl:ensure-generic-function 'ppfb_Output-val :lambda-list '(m))
(cl:defmethod ppfb_Output-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppfb_Output-val is deprecated.  Use atom_esp_listener-msg:ppfb_Output instead.")
  (ppfb_Output m))

(cl:ensure-generic-function 'ppfb_Setpoint-val :lambda-list '(m))
(cl:defmethod ppfb_Setpoint-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppfb_Setpoint-val is deprecated.  Use atom_esp_listener-msg:ppfb_Setpoint instead.")
  (ppfb_Setpoint m))

(cl:ensure-generic-function 'pplr_timestamp-val :lambda-list '(m))
(cl:defmethod pplr_timestamp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pplr_timestamp-val is deprecated.  Use atom_esp_listener-msg:pplr_timestamp instead.")
  (pplr_timestamp m))

(cl:ensure-generic-function 'pplr_Input-val :lambda-list '(m))
(cl:defmethod pplr_Input-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pplr_Input-val is deprecated.  Use atom_esp_listener-msg:pplr_Input instead.")
  (pplr_Input m))

(cl:ensure-generic-function 'pplr_Kd-val :lambda-list '(m))
(cl:defmethod pplr_Kd-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pplr_Kd-val is deprecated.  Use atom_esp_listener-msg:pplr_Kd instead.")
  (pplr_Kd m))

(cl:ensure-generic-function 'pplr_Ki-val :lambda-list '(m))
(cl:defmethod pplr_Ki-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pplr_Ki-val is deprecated.  Use atom_esp_listener-msg:pplr_Ki instead.")
  (pplr_Ki m))

(cl:ensure-generic-function 'pplr_Kp-val :lambda-list '(m))
(cl:defmethod pplr_Kp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pplr_Kp-val is deprecated.  Use atom_esp_listener-msg:pplr_Kp instead.")
  (pplr_Kp m))

(cl:ensure-generic-function 'pplr_Output-val :lambda-list '(m))
(cl:defmethod pplr_Output-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pplr_Output-val is deprecated.  Use atom_esp_listener-msg:pplr_Output instead.")
  (pplr_Output m))

(cl:ensure-generic-function 'pplr_Setpoint-val :lambda-list '(m))
(cl:defmethod pplr_Setpoint-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pplr_Setpoint-val is deprecated.  Use atom_esp_listener-msg:pplr_Setpoint instead.")
  (pplr_Setpoint m))

(cl:ensure-generic-function 'ppud_timestamp-val :lambda-list '(m))
(cl:defmethod ppud_timestamp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppud_timestamp-val is deprecated.  Use atom_esp_listener-msg:ppud_timestamp instead.")
  (ppud_timestamp m))

(cl:ensure-generic-function 'ppud_Input-val :lambda-list '(m))
(cl:defmethod ppud_Input-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppud_Input-val is deprecated.  Use atom_esp_listener-msg:ppud_Input instead.")
  (ppud_Input m))

(cl:ensure-generic-function 'ppud_Kd-val :lambda-list '(m))
(cl:defmethod ppud_Kd-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppud_Kd-val is deprecated.  Use atom_esp_listener-msg:ppud_Kd instead.")
  (ppud_Kd m))

(cl:ensure-generic-function 'ppud_Ki-val :lambda-list '(m))
(cl:defmethod ppud_Ki-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppud_Ki-val is deprecated.  Use atom_esp_listener-msg:ppud_Ki instead.")
  (ppud_Ki m))

(cl:ensure-generic-function 'ppud_Kp-val :lambda-list '(m))
(cl:defmethod ppud_Kp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppud_Kp-val is deprecated.  Use atom_esp_listener-msg:ppud_Kp instead.")
  (ppud_Kp m))

(cl:ensure-generic-function 'ppud_Output-val :lambda-list '(m))
(cl:defmethod ppud_Output-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppud_Output-val is deprecated.  Use atom_esp_listener-msg:ppud_Output instead.")
  (ppud_Output m))

(cl:ensure-generic-function 'ppud_Setpoint-val :lambda-list '(m))
(cl:defmethod ppud_Setpoint-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:ppud_Setpoint-val is deprecated.  Use atom_esp_listener-msg:ppud_Setpoint instead.")
  (ppud_Setpoint m))

(cl:ensure-generic-function 'yaw-val :lambda-list '(m))
(cl:defmethod yaw-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:yaw-val is deprecated.  Use atom_esp_listener-msg:yaw instead.")
  (yaw m))

(cl:ensure-generic-function 'pitch-val :lambda-list '(m))
(cl:defmethod pitch-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:pitch-val is deprecated.  Use atom_esp_listener-msg:pitch instead.")
  (pitch m))

(cl:ensure-generic-function 'roll-val :lambda-list '(m))
(cl:defmethod roll-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:roll-val is deprecated.  Use atom_esp_listener-msg:roll instead.")
  (roll m))

(cl:ensure-generic-function 'timestamp-val :lambda-list '(m))
(cl:defmethod timestamp-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:timestamp-val is deprecated.  Use atom_esp_listener-msg:timestamp instead.")
  (timestamp m))

(cl:ensure-generic-function 'tune_type-val :lambda-list '(m))
(cl:defmethod tune_type-val ((m <alldata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader atom_esp_listener-msg:tune_type-val is deprecated.  Use atom_esp_listener-msg:tune_type instead.")
  (tune_type m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <alldata>) ostream)
  "Serializes a message object of type '<alldata>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'mpuData_AcX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuData_AcY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuData_AcZ)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mpuData_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mpuData_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mpuData_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mpuData_timestamp)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'mpuData_Tmp)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuData_GyX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuData_GyY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuData_GyZ)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuRAW_AcX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuRAW_AcY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuRAW_AcZ)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mpuRAW_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mpuRAW_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mpuRAW_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mpuRAW_timestamp)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'mpuRAW_Tmp)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuRAW_GyX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuRAW_GyY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mpuRAW_GyZ)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pingheight))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ppfb_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ppfb_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ppfb_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ppfb_timestamp)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppfb_Input))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppfb_Kd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppfb_Ki))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppfb_Kp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppfb_Output))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppfb_Setpoint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pplr_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pplr_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'pplr_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'pplr_timestamp)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'pplr_Input))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'pplr_Kd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'pplr_Ki))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'pplr_Kp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'pplr_Output))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'pplr_Setpoint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ppud_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ppud_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ppud_timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ppud_timestamp)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppud_Input))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppud_Kd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppud_Ki))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppud_Kp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppud_Output))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ppud_Setpoint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'roll))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timestamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tune_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tune_type)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <alldata>) istream)
  "Deserializes a message object of type '<alldata>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuData_AcX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuData_AcY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuData_AcZ) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mpuData_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mpuData_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mpuData_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mpuData_timestamp)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuData_Tmp) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuData_GyX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuData_GyY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuData_GyZ) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuRAW_AcX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuRAW_AcY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuRAW_AcZ) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mpuRAW_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mpuRAW_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mpuRAW_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mpuRAW_timestamp)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuRAW_Tmp) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuRAW_GyX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuRAW_GyY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mpuRAW_GyZ) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pingheight) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ppfb_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ppfb_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ppfb_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ppfb_timestamp)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppfb_Input) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppfb_Kd) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppfb_Ki) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppfb_Kp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppfb_Output) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppfb_Setpoint) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pplr_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pplr_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'pplr_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'pplr_timestamp)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pplr_Input) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pplr_Kd) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pplr_Ki) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pplr_Kp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pplr_Output) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pplr_Setpoint) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ppud_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ppud_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ppud_timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ppud_timestamp)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppud_Input) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppud_Kd) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppud_Ki) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppud_Kp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppud_Output) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ppud_Setpoint) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'roll) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timestamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tune_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tune_type)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<alldata>)))
  "Returns string type for a message object of type '<alldata>"
  "atom_esp_listener/alldata")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'alldata)))
  "Returns string type for a message object of type 'alldata"
  "atom_esp_listener/alldata")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<alldata>)))
  "Returns md5sum for a message object of type '<alldata>"
  "586be2de32280a4c8bb4bc521bc4cf73")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'alldata)))
  "Returns md5sum for a message object of type 'alldata"
  "586be2de32280a4c8bb4bc521bc4cf73")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<alldata>)))
  "Returns full string definition for message of type '<alldata>"
  (cl:format cl:nil "Header header~%int16  mpuData_AcX~%int16  mpuData_AcY~%int16  mpuData_AcZ~%uint32  mpuData_timestamp~%int16  mpuData_Tmp~%int16  mpuData_GyX~%int16  mpuData_GyY~%int16  mpuData_GyZ~%~%int16  mpuRAW_AcX~%int16  mpuRAW_AcY~%int16  mpuRAW_AcZ~%uint32  mpuRAW_timestamp~%int16  mpuRAW_Tmp~%int16  mpuRAW_GyX~%int16  mpuRAW_GyY~%int16  mpuRAW_GyZ~%~%float32  pingheight~%~%uint32  ppfb_timestamp~%float64  ppfb_Input~%float64  ppfb_Kd~%float64  ppfb_Ki~%float64  ppfb_Kp~%float64  ppfb_Output~%float64  ppfb_Setpoint~%~%uint32  pplr_timestamp~%float64  pplr_Input~%float64  pplr_Kd~%float64  pplr_Ki~%float64  pplr_Kp~%float64  pplr_Output~%float64  pplr_Setpoint~%~%uint32  ppud_timestamp~%float64  ppud_Input~%float64  ppud_Kd~%float64  ppud_Ki~%float64  ppud_Kp~%float64  ppud_Output~%float64  ppud_Setpoint~%~%float32  yaw~%float32  pitch~%float32  roll~%~%uint32  timestamp~%uint16  tune_type~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'alldata)))
  "Returns full string definition for message of type 'alldata"
  (cl:format cl:nil "Header header~%int16  mpuData_AcX~%int16  mpuData_AcY~%int16  mpuData_AcZ~%uint32  mpuData_timestamp~%int16  mpuData_Tmp~%int16  mpuData_GyX~%int16  mpuData_GyY~%int16  mpuData_GyZ~%~%int16  mpuRAW_AcX~%int16  mpuRAW_AcY~%int16  mpuRAW_AcZ~%uint32  mpuRAW_timestamp~%int16  mpuRAW_Tmp~%int16  mpuRAW_GyX~%int16  mpuRAW_GyY~%int16  mpuRAW_GyZ~%~%float32  pingheight~%~%uint32  ppfb_timestamp~%float64  ppfb_Input~%float64  ppfb_Kd~%float64  ppfb_Ki~%float64  ppfb_Kp~%float64  ppfb_Output~%float64  ppfb_Setpoint~%~%uint32  pplr_timestamp~%float64  pplr_Input~%float64  pplr_Kd~%float64  pplr_Ki~%float64  pplr_Kp~%float64  pplr_Output~%float64  pplr_Setpoint~%~%uint32  ppud_timestamp~%float64  ppud_Input~%float64  ppud_Kd~%float64  ppud_Ki~%float64  ppud_Kp~%float64  ppud_Output~%float64  ppud_Setpoint~%~%float32  yaw~%float32  pitch~%float32  roll~%~%uint32  timestamp~%uint16  tune_type~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <alldata>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     2
     4
     2
     2
     2
     2
     2
     2
     2
     4
     2
     2
     2
     2
     4
     4
     8
     8
     8
     8
     8
     8
     4
     8
     8
     8
     8
     8
     8
     4
     8
     8
     8
     8
     8
     8
     4
     4
     4
     4
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <alldata>))
  "Converts a ROS message object to a list"
  (cl:list 'alldata
    (cl:cons ':header (header msg))
    (cl:cons ':mpuData_AcX (mpuData_AcX msg))
    (cl:cons ':mpuData_AcY (mpuData_AcY msg))
    (cl:cons ':mpuData_AcZ (mpuData_AcZ msg))
    (cl:cons ':mpuData_timestamp (mpuData_timestamp msg))
    (cl:cons ':mpuData_Tmp (mpuData_Tmp msg))
    (cl:cons ':mpuData_GyX (mpuData_GyX msg))
    (cl:cons ':mpuData_GyY (mpuData_GyY msg))
    (cl:cons ':mpuData_GyZ (mpuData_GyZ msg))
    (cl:cons ':mpuRAW_AcX (mpuRAW_AcX msg))
    (cl:cons ':mpuRAW_AcY (mpuRAW_AcY msg))
    (cl:cons ':mpuRAW_AcZ (mpuRAW_AcZ msg))
    (cl:cons ':mpuRAW_timestamp (mpuRAW_timestamp msg))
    (cl:cons ':mpuRAW_Tmp (mpuRAW_Tmp msg))
    (cl:cons ':mpuRAW_GyX (mpuRAW_GyX msg))
    (cl:cons ':mpuRAW_GyY (mpuRAW_GyY msg))
    (cl:cons ':mpuRAW_GyZ (mpuRAW_GyZ msg))
    (cl:cons ':pingheight (pingheight msg))
    (cl:cons ':ppfb_timestamp (ppfb_timestamp msg))
    (cl:cons ':ppfb_Input (ppfb_Input msg))
    (cl:cons ':ppfb_Kd (ppfb_Kd msg))
    (cl:cons ':ppfb_Ki (ppfb_Ki msg))
    (cl:cons ':ppfb_Kp (ppfb_Kp msg))
    (cl:cons ':ppfb_Output (ppfb_Output msg))
    (cl:cons ':ppfb_Setpoint (ppfb_Setpoint msg))
    (cl:cons ':pplr_timestamp (pplr_timestamp msg))
    (cl:cons ':pplr_Input (pplr_Input msg))
    (cl:cons ':pplr_Kd (pplr_Kd msg))
    (cl:cons ':pplr_Ki (pplr_Ki msg))
    (cl:cons ':pplr_Kp (pplr_Kp msg))
    (cl:cons ':pplr_Output (pplr_Output msg))
    (cl:cons ':pplr_Setpoint (pplr_Setpoint msg))
    (cl:cons ':ppud_timestamp (ppud_timestamp msg))
    (cl:cons ':ppud_Input (ppud_Input msg))
    (cl:cons ':ppud_Kd (ppud_Kd msg))
    (cl:cons ':ppud_Ki (ppud_Ki msg))
    (cl:cons ':ppud_Kp (ppud_Kp msg))
    (cl:cons ':ppud_Output (ppud_Output msg))
    (cl:cons ':ppud_Setpoint (ppud_Setpoint msg))
    (cl:cons ':yaw (yaw msg))
    (cl:cons ':pitch (pitch msg))
    (cl:cons ':roll (roll msg))
    (cl:cons ':timestamp (timestamp msg))
    (cl:cons ':tune_type (tune_type msg))
))
