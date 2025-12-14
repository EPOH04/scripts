/**
 * 智能灯状态模式实现（单文件版）
 */
public class SmartLight {
    // 状态接口（内部接口）
    private interface LightState {
        void pressOn(SmartLight light);
        void pressOff(SmartLight light);
        void adjustBrightness(SmartLight light);
    }

    // 关闭状态（内部单例类）
    private static class OffState implements LightState {
        private static final OffState INSTANCE = new OffState();

        private OffState() {}

        public static OffState getInstance() {
            return INSTANCE;
        }

        @Override
        public void pressOn(SmartLight light) {
            System.out.println("Light is on (30% brightness)");
            light.setState(LowBrightnessState.getInstance());
        }

        @Override
        public void pressOff(SmartLight light) {
            System.out.println("Light is already off");
        }

        @Override
        public void adjustBrightness(SmartLight light) {
            System.out.println("Light is off - cannot adjust brightness");
        }
    }

    // 低亮度状态（内部单例类）
    private static class LowBrightnessState implements LightState {
        private static final LowBrightnessState INSTANCE = new LowBrightnessState();

        private LowBrightnessState() {}

        public static LowBrightnessState getInstance() {
            return INSTANCE;
        }

        @Override
        public void pressOn(SmartLight light) {
            System.out.println("Light is already on (30% brightness)");
        }

        @Override
        public void pressOff(SmartLight light) {
            System.out.println("Light is off");
            light.setState(OffState.getInstance());
        }

        @Override
        public void adjustBrightness(SmartLight light) {
            System.out.println("Light adjusted to 70% brightness");
            light.setState(MediumBrightnessState.getInstance());
        }
    }

    // 中亮度状态（内部单例类）
    private static class MediumBrightnessState implements LightState {
        private static final MediumBrightnessState INSTANCE = new MediumBrightnessState();

        private MediumBrightnessState() {}

        public static MediumBrightnessState getInstance() {
            return INSTANCE;
        }

        @Override
        public void pressOn(SmartLight light) {
            System.out.println("Light is already on (70% brightness)");
        }

        @Override
        public void pressOff(SmartLight light) {
            System.out.println("Light is off");
            light.setState(OffState.getInstance());
        }

        @Override
        public void adjustBrightness(SmartLight light) {
            System.out.println("Light adjusted to 100% brightness");
            light.setState(HighBrightnessState.getInstance());
        }
    }

    // 高亮度状态（内部单例类）
    private static class HighBrightnessState implements LightState {
        private static final HighBrightnessState INSTANCE = new HighBrightnessState();

        private HighBrightnessState() {}

        public static HighBrightnessState getInstance() {
            return INSTANCE;
        }

        @Override
        public void pressOn(SmartLight light) {
            System.out.println("Light is already on (100% brightness)");
        }

        @Override
        public void pressOff(SmartLight light) {
            System.out.println("Light is off");
            light.setState(OffState.getInstance());
        }

        @Override
        public void adjustBrightness(SmartLight light) {
            System.out.println("Light adjusted to 30% brightness");
            light.setState(LowBrightnessState.getInstance());
        }
    }

    // 智能灯核心逻辑
    private LightState currentState;

    public SmartLight() {
        this.currentState = OffState.getInstance();
    }

    public void setState(LightState state) {
        this.currentState = state;
    }

    public void pressOn() {
        currentState.pressOn(this);
    }

    public void pressOff() {
        currentState.pressOff(this);
    }

    public void adjustBrightness() {
        currentState.adjustBrightness(this);
    }

    // 主方法：测试示例
    public static void main(String[] args) {
        SmartLight light = new SmartLight();

        light.pressOn();                // Light is on (30% brightness)
        light.adjustBrightness();       // Light adjusted to 70% brightness
        light.adjustBrightness();       // Light adjusted to 100% brightness
        light.adjustBrightness();       // Light adjusted to 30% brightness
        light.pressOff();               // Light is off
        light.adjustBrightness();       // Light is off - cannot adjust brightness
    }
}
