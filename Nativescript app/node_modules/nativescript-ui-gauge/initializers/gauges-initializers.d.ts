import * as commonInitializers from "./gauges-initializers.common";
import * as commonModule from "../ui-gauge.common";
import { ObservableArray } from "tns-core-modules/data/observable-array";
export declare class RadGaugeValueMapper implements commonInitializers.RadGaugeValueMapper {
    onTitleChanged(oldValue: string, newValue: string, gauge: commonModule.RadGauge): void;
    onSubtitleChanged(oldValue: string, newValue: string, gauge: commonModule.RadGauge): void;
    onTitleStyleChanged(oldValue: commonModule.TitleStyle, newValue: commonModule.TitleStyle, gauge: commonModule.RadGauge): void;
    onSubtitleStyleChanged(oldValue: commonModule.SubtitleStyle, newValue: commonModule.SubtitleStyle, gauge: commonModule.RadGauge): void;
    updateNativeObject(gauge: commonModule.RadGauge): void;
}
export declare class GaugeScaleValueMapper implements commonInitializers.GaugeScaleValueMapper {
    onMinimumChanged(oldValue: number, newValue: number, scale: commonModule.GaugeScale): void;
    onMaximumChanged(oldValue: number, newValue: number, scale: commonModule.GaugeScale): void;
    onIndicatorsChange(oldValue: ObservableArray<commonModule.GaugeIndicator>, newValue: ObservableArray<commonModule.GaugeIndicator>, scale: commonModule.GaugeScale): void;
    onScaleStyleChanged(oldValue: commonModule.ScaleStyle, newValue: commonModule.ScaleStyle, scale: commonModule.GaugeScale): void;
    reloadIndicators(scale: commonModule.GaugeScale): void;
    updateNativeObject(scale: commonModule.GaugeScale): void;
}
export declare class NeedleIndicatorValueMapper implements commonInitializers.NeedleIndicatorValueMapper {
    onIsAnimatedChanged(oldValue: boolean, newValue: boolean, indicator: commonModule.GaugeIndicator): void;
    onAnimationDurationChanged(oldValue: number, newValue: number, indicator: commonModule.GaugeIndicator): void;
    onNeedleStyleChanged(oldValue: commonModule.NeedleStyle, newValue: commonModule.NeedleStyle, needle: commonModule.RadialNeedle): void;
    updateNativeObject(needle: commonModule.RadialNeedle): void;
}
export declare class BarIndicatorValueMapper implements commonInitializers.BarIndicatorValueMapper {
    onIsAnimatedChanged(oldValue: boolean, newValue: boolean, indicator: commonModule.GaugeIndicator): void;
    onAnimationDurationChanged(oldValue: number, newValue: number, indicator: commonModule.GaugeIndicator): void;
    onMinimumValueChanged(oldValue: number, newValue: number, indicator: commonModule.BarIndicator): void;
    onMaximumValueChanged(oldValue: number, newValue: number, indicator: commonModule.BarIndicator): void;
    onIndicatorStyleChanged(oldValue: commonModule.BarIndicatorStyle, newValue: commonModule.BarIndicatorStyle, indicator: commonModule.BarIndicator): void;
    onLocationChanged(oldValue: number, newValue: number, indicator: commonModule.BarIndicator): void;
    updateNativeObject(barIndicator: commonModule.BarIndicator): void;
}
