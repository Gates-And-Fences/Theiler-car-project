// ESP32 RC Car Telemetry Simulation
// Web-based simulation of the telemetry demo

class RCTelemetrySimulator {
    constructor() {
        // DOM Elements
        this.voltageControl = document.getElementById('voltage-control');
        this.currentControl = document.getElementById('current-control');
        this.motorToggle = document.getElementById('motor-toggle');
        this.voltageValue = document.getElementById('voltage-value');
        this.currentValue = document.getElementById('current-value');
        this.batteryVoltage = document.getElementById('battery-voltage');
        this.motorCurrent = document.getElementById('motor-current');
        this.motorStatus = document.getElementById('motor-status');
        this.car = document.querySelector('.car');
        
        // State variables
        this.motorRunning = false;
        this.batteryVoltageValue = 7.4;
        this.motorCurrentValue = 0.0;
        
        // Initialize the simulation
        this.init();
    }
    
    init() {
        // Set up event listeners
        this.voltageControl.addEventListener('input', (e) => {
            this.batteryVoltageValue = parseFloat(e.target.value);
            this.updateDisplay();
        });
        
        this.currentControl.addEventListener('input', (e) => {
            this.motorCurrentValue = parseFloat(e.target.value);
            this.updateDisplay();
        });
        
        this.motorToggle.addEventListener('click', () => {
            this.toggleMotor();
        });
        
        // Initial display update
        this.updateDisplay();
        
        // Simulate periodic updates
        setInterval(() => {
            this.simulateTelemetry();
        }, 1000);
    }
    
    updateDisplay() {
        // Update control labels
        this.voltageValue.textContent = this.batteryVoltageValue.toFixed(1);
        this.currentValue.textContent = this.motorCurrentValue.toFixed(1);
        
        // Update telemetry display
        this.batteryVoltage.textContent = this.batteryVoltageValue.toFixed(2) + ' V';
        this.motorCurrent.textContent = this.motorCurrentValue.toFixed(3) + ' A';
        this.motorStatus.textContent = this.motorRunning ? 'ON' : 'OFF';
        this.motorStatus.className = 'value ' + (this.motorRunning ? 'motor-on' : 'motor-off');
        
        // Update car appearance based on motor status
        if (this.motorRunning) {
            this.car.classList.add('motor-on');
        } else {
            this.car.classList.remove('motor-on');
        }
    }
    
    toggleMotor() {
        this.motorRunning = !this.motorRunning;
        
        // Update button text
        this.motorToggle.textContent = this.motorRunning ? 'Stop Motor' : 'Start Motor';
        this.motorToggle.className = this.motorRunning ? 'motor-on' : '';
        
        // When motor is turned on, increase current draw
        if (this.motorRunning) {
            // Set a minimum current draw when motor is on
            if (this.motorCurrentValue < 0.5) {
                this.motorCurrentValue = 0.5 + Math.random() * 1.5;
                this.currentControl.value = this.motorCurrentValue;
            }
        }
        
        this.updateDisplay();
    }
    
    simulateTelemetry() {
        // Simulate small fluctuations in voltage and current
        if (this.motorRunning) {
            // When motor is running, voltage might drop slightly due to load
            const voltageDrop = 0.1 + Math.random() * 0.2;
            const newVoltage = Math.max(6.0, this.batteryVoltageValue - voltageDrop * 0.01);
            this.batteryVoltageValue = newVoltage;
            this.voltageControl.value = newVoltage;
            
            // Current might fluctuate when motor is running
            const currentVariation = (Math.random() - 0.5) * 0.2;
            this.motorCurrentValue = Math.max(0.1, this.motorCurrentValue + currentVariation);
            this.currentControl.value = this.motorCurrentValue;
        } else {
            // When motor is off, voltage slowly recovers
            const voltageRecovery = 0.05 + Math.random() * 0.1;
            const newVoltage = Math.min(8.4, this.batteryVoltageValue + voltageRecovery * 0.01);
            this.batteryVoltageValue = newVoltage;
            this.voltageControl.value = newVoltage;
            
            // Current drops to near zero when motor is off
            this.motorCurrentValue = Math.max(0.0, this.motorCurrentValue - 0.1);
            this.currentControl.value = this.motorCurrentValue;
        }
        
        this.updateDisplay();
    }
}

// Initialize the simulation when the page loads
document.addEventListener('DOMContentLoaded', () => {
    new RCTelemetrySimulator();
});