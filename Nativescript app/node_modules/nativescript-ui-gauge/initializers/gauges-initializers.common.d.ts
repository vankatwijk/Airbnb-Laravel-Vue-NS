import * as commonModule from "../ui-gauge.common";
import { ObservableArray } from "tns-core-modules/data/observable-array";
export interface RadGaugeValueMapper {
    onTitleChanged(oldValue: string, newValue: string, gauge: commonModule.RadGauge): any;
    onSubtitleChanged(oldValue: string, newValue: string, gauge: commonModule.RadGauge): any;
    onTitleStyleChanged(oldValue: commonModule.TitleStyle, newValue: commonModule.TitleStyle, gauge: commonModule.RadGauge): any;
    onSubtitleStyleChanged(oldValue: commonModule.SubtitleStyle, newValue: commonModule.SubtitleStyle, gauge: commonModule.RadGauge): any;
}
export interface GaugeScaleValueMapper {
    onMinimumChanged(oldValue: number, newValue: number, scale: commonModule.GaugeScale): any;
    onMaximumChanged(oldValue: number, newValue: number, scale: commonModule.GaugeScale): any;
    onIndicatorsChange(oldValue: ObservableArray<commonModule.GaugeIndicator>, newValue: ObservableArray<commonModule.GaugeIndicator>, scale: commonModule.GaugeScale): any;
    onScaleStyleChanged(oldValue: commonModule.ScaleStyle, newValue: commonModule.ScaleStyle, scale: commonModule.GaugeScale): any;
}
export interface GaugeIndicatorValueMapper {
    onIsAnimatedChanged(oldValue: boolean, newValue: boolean, indicator: commonModule.GaugeIndicator): any;
    onAnimationDurationChanged(oldValue: number, newValue: number, indicator: commonModule.GaugeIndicator): any;
}
export interface NeedleIndicatorValueMapper extends GaugeIndicatorValueMapper {
    onNeedleStyleChanged(oldValue: commonModule.NeedleStyle, newValue: commonModule.NeedleStyle, needle: commonModule.RadialNeedle): any;
}
export interface BarIndicatorValueMapper extends GaugeIndicatorValueMapper {
    onMinimumValueChanged(oldValue: number, newValue: number, indicator: commonModule.BarIndicator): any;
    onMaximumValueChanged(oldValue: number, newValue: number, indicator: commonModule.BarIndicator): any;
    onIndicatorStyleChanged(oldValue: commonModule.BarIndicatorStyle, newValue: commonModule.BarIndicatorStyle, indicator: commonModule.BarIndicator): any;
    onLocationChanged(oldValue: number, newValue: number, indicator: commonModule.BarIndicator): any;
}
