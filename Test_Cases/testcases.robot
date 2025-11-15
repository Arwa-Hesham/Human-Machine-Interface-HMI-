*** Settings ***
Documentation    Embedded Systems Project Test Cases

*** Test Cases ***
Test Case 1: System Initialization
    [Documentation]    Verify that the system initializes all modules correctly after power-on.
    # Arrange (Set up the test environment)
    Power on the microcontroller with all sensors, LCD, and buttons connected.
    # Act (Perform the action to be tested)
    Observe the LCD for initialization messages and check if all peripherals respond.
    # Assert (Verify the expected outcome)
    LCD should show a welcome message.
    No error indicators should appear.
    All modules should be ready for user interaction.

Test Case 2: Button Debounce Functionality
    [Documentation]    Ensure that a single button press is registered only once.
    # Arrange (Set up the test environment)
    System is powered on and ready.
    # Act (Perform the action to be tested)
    Quickly press and release any of the limit-setting buttons multiple times.
    # Assert (Verify the expected outcome)
    Only one increment/decrement/reset occurs per valid button press.

Test Case 3: Temperature Sensor Reading and Display
    [Documentation]    Confirm that the temperature sensor value is correctly acquired and displayed.
    # Arrange (Set up the test environment)
    Apply a known temperature to the sensor (use a reference thermometer if needed).
    # Act (Perform the action to be tested)
    Read the value shown on the LCD in temperature display mode.
    # Assert (Verify the expected outcome)
    Value on LCD should match (within tolerance) the reference temperature.

Test Case 4: LDR Sensor Reading and Display
    [Documentation]    Confirm that the LDR sensor value is correctly acquired and displayed.
    # Arrange (Set up the test environment)
    Provide a controlled light source to the LDR.
    # Act (Perform the action to be tested)
    Read the value shown on the LCD in LDR display mode.
    # Assert (Verify the expected outcome)
    Value on LCD should increase as light intensity increases and decrease as it is blocked.

Test Case 5: Display Mode Button
    [Documentation]    Ensure the display switches between temperature, LDR, and both as per button presses.
    # Arrange (Set up the test environment)
    System is running and sensors are producing valid signals.
    # Act (Perform the action to be tested)
    Press the display mode button once; repeat multiple times.
    # Assert (Verify the expected outcome)
    LCD cycles between temperature, LDR, and both modes as expected.

Test Case 6: Increase and Decrease Limit Values
    [Documentation]    Ensure increment/decrement buttons adjust chosen limit properly.
    # Arrange
    Select a limit (e.g., LM35 upper limit).
    # Act
    Press increment and then decrement buttons.
    # Assert
    Limit value increases or decreases as expected and is updated on LCD.
    
Test Case 7: Limit Crossing Alert
    [Documentation]    Verify that alerts (LED/Buzzer) are triggered when limits are exceeded.
    # Arrange (Set up the test environment)
    Set thresholds low and apply conditions so that temperature or light intensity exceed limits.
    # Act (Perform the action to be tested)
    Continuously monitor outputs as the sensor values cross set thresholds.
    # Assert (Verify the expected outcome)
    LED or buzzer activates immediately as the threshold is crossed; deactivates when back within limits.
*** Settings ***
Documentation    LCD Keypad Shield Project with LM35 & LDR Test Cases

Test Case 8: Button Debounce & Responsiveness
    [Documentation]    Ensure single button presses are registered once, and no false triggers.
    # Arrange
    System running, buttons ready.
    # Act
    Rapidly tap each button multiple times.
    # Assert
    Each press increments only once. No skipped or double-inputs.

Test Case 9: Sensor Value Refresh Rate
    [Documentation]    Verify that both sensor readings update on the LCD at the expected rate.
    # Arrange (Set up the test environment)
    System powered on with changing sensor inputs.
    # Act
    Gradually change LM35 temperature and LDR light intensity.
    # Assert
    Readings update on the display with no noticeable lag (e.g., at least once per second).

Test Case 10: Multiple Limit Updates in Sequence
    [Documentation]    Test system handling of rapid limit selection and adjustment.
    # Arrange
    Ready system with all buttons functional.
    # Act
    Rapidly select upper/lower limits for LM35 and LDR, increasing/decreasing values with each selection.
    # Assert
    All changes are correctly registered and displayed; no mix-up between sensors or limit types.