declare class TKGauge extends TKView {

	static alloc(): TKGauge; // inherited from NSObject

	static appearance(): TKGauge; // inherited from UIAppearance

	static appearanceForTraitCollection(trait: UITraitCollection): TKGauge; // inherited from UIAppearance

	static appearanceForTraitCollectionWhenContainedIn(trait: UITraitCollection, ContainerClass: typeof NSObject): TKGauge; // inherited from UIAppearance

	static appearanceForTraitCollectionWhenContainedInInstancesOfClasses(trait: UITraitCollection, containerTypes: NSArray<typeof NSObject>): TKGauge; // inherited from UIAppearance

	static appearanceWhenContainedIn(ContainerClass: typeof NSObject): TKGauge; // inherited from UIAppearance

	static appearanceWhenContainedInInstancesOfClasses(containerTypes: NSArray<typeof NSObject>): TKGauge; // inherited from UIAppearance

	static new(): TKGauge; // inherited from NSObject

	delegate: TKGaugeDelegate;

	insets: UIEdgeInsets;

	readonly labelSubtitle: UILabel;

	labelSubtitleOffset: CGPoint;

	readonly labelTitle: UILabel;

	labelTitleOffset: CGPoint;

	rectWithInsets: CGRect;

	readonly scales: NSArray<TKGaugeScale>;

	addScale(scale: TKGaugeScale): void;

	insertScaleAtIndex(scale: TKGaugeScale, index: number): void;

	removeAllScales(): void;

	removeScale(scale: TKGaugeScale): void;

	removeScaleAtIndex(index: number): void;

	scaleAtIndex(index: number): TKGaugeScale;
}

interface TKGaugeDelegate extends NSObjectProtocol {

	gaugeTextForLabel?(gauge: TKGauge, label: any): string;

	gaugeValueChangedForScale?(gauge: TKGauge, value: number, scale: TKGaugeScale): void;
}
declare var TKGaugeDelegate: {

	prototype: TKGaugeDelegate;
};

declare class TKGaugeIndicator extends CALayer {

	static alloc(): TKGaugeIndicator; // inherited from NSObject

	static layer(): TKGaugeIndicator; // inherited from CALayer

	static new(): TKGaugeIndicator; // inherited from NSObject

	allowTouch: boolean;

	fill: TKFill;

	owner: TKGaugeScale;

	stroke: TKStroke;

	value: number;
}

declare class TKGaugeLabels extends NSObject {

	static alloc(): TKGaugeLabels; // inherited from NSObject

	static new(): TKGaugeLabels; // inherited from NSObject

	color: UIColor;

	count: number;

	font: UIFont;

	formatter: NSFormatter;

	hidden: boolean;

	labelFormat: string;

	offset: number;

	position: TKGaugeLabelsPosition;
}

declare const enum TKGaugeLabelsPosition {

	TKGaugeLabelsPositionInner = 0,

	TKGaugeLabelsPositionOuter = 1
}

declare class TKGaugeLinearScale extends TKGaugeScale {

	static alloc(): TKGaugeLinearScale; // inherited from NSObject

	static layer(): TKGaugeLinearScale; // inherited from CALayer

	static new(): TKGaugeLinearScale; // inherited from NSObject

	endPoint: number;

	offset: number;

	startPoint: number;
}

declare class TKGaugeNeedle extends TKGaugeIndicator {

	static alloc(): TKGaugeNeedle; // inherited from NSObject

	static layer(): TKGaugeNeedle; // inherited from CALayer

	static new(): TKGaugeNeedle; // inherited from NSObject

	circleFill: TKFill;

	circleInnerRadius: number;

	circleRadius: number;

	circleStroke: TKStroke;

	length: number;

	offset: number;

	topWidth: number;

	width: number;

	constructor(o: { value: number; });

	constructor(o: { value: number; length: number; });

	initWithValue(value: number): this;

	initWithValueLength(value: number, length: number): this;

	setValueAnimatedWithDurationMediaTimingFunction(value: number, duration: number, functionName: string): void;
}

declare class TKGaugeRadialScale extends TKGaugeScale {

	static alloc(): TKGaugeRadialScale; // inherited from NSObject

	static layer(): TKGaugeRadialScale; // inherited from CALayer

	static new(): TKGaugeRadialScale; // inherited from NSObject

	endAngle: number;

	radius: number;

	startAngle: number;
}

declare class TKGaugeScale extends CALayer {

	static alloc(): TKGaugeScale; // inherited from NSObject

	static layer(): TKGaugeScale; // inherited from CALayer

	static new(): TKGaugeScale; // inherited from NSObject

	fill: TKFill;

	readonly indicators: NSArray<TKGaugeIndicator>;

	readonly labels: TKGaugeLabels;

	owner: TKGauge;

	range: TKRange;

	readonly segments: NSArray<TKGaugeSegment>;

	stroke: TKStroke;

	readonly ticks: TKGaugeTicks;

	constructor(o: { minimum: any; maximum: any; });

	constructor(o: { range: TKRange; });

	addIndicator(indicator: TKGaugeIndicator): void;

	addSegment(segment: TKGaugeSegment): void;

	denormalize(value: number): number;

	indicatorAtIndex(index: number): TKGaugeIndicator;

	initWithMinimumMaximum(minimum: any, maximum: any): this;

	initWithRange(range: TKRange): this;

	insertIndicatorAtIndex(indicator: TKGaugeIndicator, index: number): void;

	insertSegmentAtIndex(segment: TKGaugeSegment, index: number): void;

	locationForValue(value: number): number;

	removeAllIndicators(): void;

	removeAllSegments(): void;

	removeIndicator(indicator: TKGaugeIndicator): void;

	removeIndicatorAtIndex(index: number): void;

	removeSegment(segment: TKGaugeSegment): void;

	removeSegmentAtIndex(index: number): void;

	segmentAtIndex(index: number): TKGaugeSegment;

	textForValue(value: number): string;

	valueForPoint(point: CGPoint): number;
}

declare class TKGaugeSegment extends CALayer {

	static alloc(): TKGaugeSegment; // inherited from NSObject

	static layer(): TKGaugeSegment; // inherited from CALayer

	static new(): TKGaugeSegment; // inherited from NSObject

	allowTouch: boolean;

	cap: TKGaugeSegmentCap;

	fill: TKFill;

	location: number;

	owner: TKGaugeScale;

	range: TKRange;

	stroke: TKStroke;

	width: number;

	width2: number;

	constructor(o: { minimum: any; maximum: any; });

	constructor(o: { range: TKRange; });

	initWithMinimumMaximum(minimum: any, maximum: any): this;

	initWithRange(range: TKRange): this;

	setRangeAnimatedWithDurationMediaTimingFunction(value: TKRange, duration: number, functionName: string): void;
}

declare const enum TKGaugeSegmentCap {

	Round = 0,

	Edge = 1
}

declare class TKGaugeTicks extends NSObject {

	static alloc(): TKGaugeTicks; // inherited from NSObject

	static new(): TKGaugeTicks; // inherited from NSObject

	hidden: boolean;

	majorTicksCount: number;

	majorTicksFill: TKFill;

	majorTicksLength: number;

	majorTicksStroke: TKStroke;

	majorTicksWidth: number;

	minorTicksCount: number;

	minorTicksFill: TKFill;

	minorTicksLength: number;

	minorTicksStroke: TKStroke;

	minorTicksWidth: number;

	offset: number;

	position: TKGaugeTicksPosition;
}

declare const enum TKGaugeTicksPosition {

	Inner = 0,

	Outer = 1
}

declare class TKLinearGauge extends TKGauge {

	static alloc(): TKLinearGauge; // inherited from NSObject

	static appearance(): TKLinearGauge; // inherited from UIAppearance

	static appearanceForTraitCollection(trait: UITraitCollection): TKLinearGauge; // inherited from UIAppearance

	static appearanceForTraitCollectionWhenContainedIn(trait: UITraitCollection, ContainerClass: typeof NSObject): TKLinearGauge; // inherited from UIAppearance

	static appearanceForTraitCollectionWhenContainedInInstancesOfClasses(trait: UITraitCollection, containerTypes: NSArray<typeof NSObject>): TKLinearGauge; // inherited from UIAppearance

	static appearanceWhenContainedIn(ContainerClass: typeof NSObject): TKLinearGauge; // inherited from UIAppearance

	static appearanceWhenContainedInInstancesOfClasses(containerTypes: NSArray<typeof NSObject>): TKLinearGauge; // inherited from UIAppearance

	static new(): TKLinearGauge; // inherited from NSObject

	labelOrientation: TKLinearGaugeOrientation;

	labelPosition: TKLinearGaugeLabelPosition;

	labelSpacing: number;

	orientation: TKLinearGaugeOrientation;
}

declare const enum TKLinearGaugeLabelPosition {

	TopOrLeft = 0,

	BottomOrRight = 1
}

declare const enum TKLinearGaugeOrientation {

	Horizontal = 0,

	Vertical = 1
}

declare class TKRadialGauge extends TKGauge {

	static alloc(): TKRadialGauge; // inherited from NSObject

	static appearance(): TKRadialGauge; // inherited from UIAppearance

	static appearanceForTraitCollection(trait: UITraitCollection): TKRadialGauge; // inherited from UIAppearance

	static appearanceForTraitCollectionWhenContainedIn(trait: UITraitCollection, ContainerClass: typeof NSObject): TKRadialGauge; // inherited from UIAppearance

	static appearanceForTraitCollectionWhenContainedInInstancesOfClasses(trait: UITraitCollection, containerTypes: NSArray<typeof NSObject>): TKRadialGauge; // inherited from UIAppearance

	static appearanceWhenContainedIn(ContainerClass: typeof NSObject): TKRadialGauge; // inherited from UIAppearance

	static appearanceWhenContainedInInstancesOfClasses(containerTypes: NSArray<typeof NSObject>): TKRadialGauge; // inherited from UIAppearance

	static new(): TKRadialGauge; // inherited from NSObject

	labelSpacing: number;
}