import cv2
import mediapipe as mp
import winsound

mp_drawing = mp.solutions.drawing_utils
myPose = mp.solutions.pose
poses = myPose.Pose()

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    frame = imutils.resize(frame, width=800)
    results = poses.process(frame)
    frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)

    if results.pose_landmarks:
        mp_drawing.draw_landmarks(frame, results.pose_landmarks, myPose.POSE_CONNECTIONS)

        winsound.Beep(1000, 100)  # Beep at 1000 Hz for 100 ms

    cv2.imshow('Anti-Human', frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
