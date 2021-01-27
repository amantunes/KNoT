clear all
close all

tic
for c = 1:11
    switch c
        case 1
            data = csvread('20b_ds_mst_92_bg2_5k.csv');
            data(:,2) = [];
            n = 0.5;
            lsb = 1.024 / 2^21 * 10^6;
            figure(c)
            sgtitle({'20-bit DelSig ADC, Multi Sample (Turbo), SR = 92 SPS, Buf. Gain = 2, 5.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 2
            data = csvread('20b_ds_mst_182_bg1_5k.csv');
            data(:,2) = [];
            n = 0.5;
            lsb = 1.024 / 2^20 * 10^6;
            figure(c)
            sgtitle({'20-bit DelSig ADC, Multi Sample (Turbo), SR = 182 SPS, Buf. Gain = 1, 5.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 3
            data = csvread('18b_ds_mst_1238_bg2_10k.csv');
            data(:,2) = [];
            n = 1;
            lsb = 1.024 / 2^19 * 10^6;
            figure(c)
            sgtitle({'18-bit DelSig ADC, Multi Sample (Turbo), SR = 1238 SPS, Buf. Gain = 2, 10.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 4
            data = csvread('18b_ds_mst_2477_bg1_10k.csv');
            data(:,2) = [];
            n = 1;
            lsb = 1.024 / 2^18 * 10^6;
            figure(c)
            sgtitle({'18-bit DelSig ADC, Multi Sample (Turbo), SR = 2477 SPS, Buf. Gain = 1, 10.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 5
            data = csvread('16b_ds_mst_5505_bg2_20k.csv');
            data(:,2) = [];
            n = 2;
            lsb = 1.024 / 2^17 * 10^6;
            figure(c)
            sgtitle({'16-bit DelSig ADC, Multi Sample (Turbo), SR = 5505 SPS, Buf. Gain = 2, 20.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 6 
            data = csvread('16b_ds_mst_11010_bg1_20k.csv');
            data(:,2) = [];
            n = 2;
            lsb = 1.024 / 2^16 * 10^6;
            figure(c)
            sgtitle({'16-bit DelSig ADC, Multi Sample (Turbo), SR = 11010 SPS, Buf. Gain = 1, 20.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 7
            data = csvread('14b_ds_mst_14840_bg2_20k.csv');
            data(:,2) = [];
            n = 2;
            lsb = 1.024 / 2^15 * 10^6;
            figure(c)
            sgtitle({'14-bit DelSig ADC, Multi Sample (Turbo), SR = 14840 SPS, Buf. Gain = 2, 20.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 8
            data = csvread('14b_ds_mst_29681_bg1_20k.csv');
            data(:,2) = [];
            n = 2;
            lsb = 1.024 / 2^14 * 10^6;
            figure(c)
            sgtitle({'14-bit DelSig ADC, Multi Sample (Turbo), SR = 29681 SPS, Buf. Gain = 1, 20.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 9
            data = csvread('20b_ds_mst_182_bg1_5k_high.csv');
            data(:,2) = [];
            n = 0.5;
            lsb = 1.024 / 2^20 * 10^6;
            figure(c)
            sgtitle({'High value resistors, 20-bit DelSig ADC, Multi Sample (Turbo), SR = 182 SPS, Buf. Gain = 1, 5.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 10
            data = csvread('18b_ds_mst_2477_bg1_10k_high.csv');
            data(:,2) = [];
            n = 1;
            lsb = 1.024 / 2^18 * 10^6;
            figure(c)
            sgtitle({'High value resistors, 18-bit DelSig ADC, Multi Sample (Turbo), SR = 2477 SPS, Buf. Gain = 1, 10.000 Samples per Measurement', ' '}, 'FontSize', 28);
        case 11
            data = csvread('16b_ds_mst_11010_bg1_20k_high.csv');
            data(:,2) = [];
            n = 2;
            lsb = 1.024 / 2^16 * 10^6;
            figure(c)
            sgtitle({'High value resistors, 16-bit DelSig ADC, Multi Sample (Turbo), SR = 11010 SPS, Buf. Gain = 1, 20.000 Samples per Measurement', ' '}, 'FontSize', 28);
    end

    setGlobala(1);
    set(gcf, 'Position',  [100, 100, 1600, 900])

    data_1u_22r = data(1:(n * 10000));
    data_1u_465r = data((1 + n * 10000):(n * 20000));
    data_1u_992r = data((1 + n * 20000):(n * 30000));

    data_10u_22r = data((1 + n * 30000):(n * 40000));
    data_10u_465r = data((1 + n * 40000):(n * 50000));
    data_10u_992r = data((1 + n * 50000):(n * 60000));

    data_100u_22r = data((1 + n * 60000):(n * 70000));
    data_100u_465r = data((1 + n * 70000):(n * 80000));
    data_100u_992r = data((1 + n * 80000):(n * 90000));

    [n1, n991, m1, s1, nlsb1] = process(data_1u_22r, lsb, 22, 1);
    [n2, n992, m2, s2, nlsb2] = process(data_1u_465r, lsb, 465, 1);
    [n3, n993, m3, s3, nlsb3] = process(data_1u_992r, lsb, 992, 1);
    [n4, n994, m4, s4, nlsb4] = process(data_10u_22r, lsb, 22, 10);
    [n5, n995, m5, s5, nlsb5] = process(data_10u_465r, lsb, 465, 10);
    [n6, n996, m6, s6, nlsb6] = process(data_10u_992r, lsb, 992, 10);
    [n7, n997, m7, s7, nlsb7] = process(data_100u_22r, lsb, 22, 100);
    [n8, n998, m8, s8, nlsb8] = process(data_100u_465r, lsb, 465, 100);
    [n9, n999, m9, s9, nlsb9] = process(data_100u_992r, lsb, 992, 100);

    m4 = m4 / 10; m5 = m5 / 10; m6 = m6 / 10;
    s4 = s4 / 10; s5 = s5 / 10; s6 = s6 / 10;

    m7 = m7 / 100; m8 = m8 / 100; m9 = m9 / 100;
    s7 = s7 / 100; s8 = s8 / 100; s9 = s9 / 100;
    
%     figure(1);

    subplot(1,3,1)
    x1 = [m1,m4,m7];
    y1 = 1:3;
    bar(y1, x1, 'FaceColor', [0.25, 0.25, 0.25])
    xticklabels({'1\mu', '10\mu', '100\mu'})
    if (c < 9)
        title({'22\Omega Resistor' , '(Measured at 21.7\Omega)'}, 'FontSize', 18)
    end
    if (c > 8)
        title({'3.3K\Omega Resistor' , '(Measured at 3.28K\Omega)'}, 'FontSize', 18)
    end
    ylim([0 50]);
    errlow = [2*s1 2*s4 2*s7];
    errhigh = [2*s1 2*s4 2*s7];
    hold on
    ax = plot(xlim,[21.7 21.7], 'LineWidth', 2);
    ax.Color = [0, 0.4470 0.7410];
    er = errorbar(y1, x1, errlow, errhigh);
    er.Color = 'r';
    er.LineStyle = 'none';
    er.LineWidth = 2;
    hold off
    xlabel('Polarization Current (A)', 'FontSize', 16);
    ylabel('Measured Resistor Value (\Omega)', 'FontSize', 16);
    ax = gca;
    ax.XAxis.FontSize = 16;
    ax.YAxis.FontSize = 16;

    subplot(1,3,2)
    x2 = [m2,m5,m8];
    bar(y1 ,x2, 'FaceColor', [0.25, 0.25, 0.25]);
    xticklabels({'1\mu', '10\mu', '100\mu'})
    if (c < 9)
        title({'470\Omega Resistor', '(Measured at 465\Omega)'}, 'FontSize', 18)
    end
    if (c > 8)
        title({'6.8K\Omega Resistor' , '(Measured at 6.76K\Omega)'}, 'FontSize', 18)
    end
    ylim([0 600]);
    errlow = [2*s2 2*s5 2*s8];
    errhigh = [2*s2 2*s5 2*s8];
    hold on
    ax = plot(xlim,[465 465], 'LineWidth', 2);
    ax.Color = [0, 0.4470 0.7410];
    er = errorbar(y1, x2, errlow, errhigh);
    er.Color = 'r';
    er.LineStyle = 'none';
    er.LineWidth = 2;
    hold off
    xlabel('Polarization Current (A)', 'FontSize', 16);
    ylabel('Measured Resistor Value (\Omega)', 'FontSize', 16);
    ax = gca;
    ax.XAxis.FontSize = 16;
    ax.YAxis.FontSize = 16;

    subplot(1,3,3)
    x3 = [m3,m6,m9];
    bar(y1, x3, 'FaceColor', [0.25, 0.25, 0.25])
    xticklabels({'1\mu', '10\mu', '100\mu'})
    if (c < 9)
        title({'1K\Omega Resistor' , '(Measured at 992\Omega)'}, 'FontSize', 18)
    end
    if (c > 8)
        title({'10K\Omega Resistor' , '(Measured at 9.90K\Omega)'}, 'FontSize', 18)
    end
    ylim([0 1200]);
    errlow = [2*s3 2*s6 2*s9];
    errhigh = [2*s3 2*s6 2*s9];
    hold on
    ax = plot(xlim,[992 992], 'LineWidth', 2);
    ax.Color = [0, 0.4470 0.7410];
    er = errorbar(y1, x3, errlow, errhigh);
    er.Color = 'r';
    er.LineStyle = 'none';
    er.LineWidth = 2;
    hold off
    xlabel('Polarization Current (A)', 'FontSize', 16);
    ylabel('Measured Resistor Value (\Omega)', 'FontSize', 16);
    ax = gca;
    ax.XAxis.FontSize = 16;
    ax.YAxis.FontSize = 16;
    
    figHandles = findall(0,'Type','figure'); 
    
    syms fig_bit;
    eqn = 2 == nthroot(lsb * 10^(-6), fig_bit);
    bits = solve(eqn, fig_bit);
    bits = abs(round(bits));
    
    bits = double(bits);
    text3 = [num2str(bits), 'bits'];
    fn = text3;
    
    
%     export_fig(fn, '-pdf', figHandles(1))
%     for i = numel(figHandles):-1:2
%      export_fig(fn, '-pdf', figHandles(i), '-append')
%     end
    
end
toc

function [noise, noise99, m, s, nlsb] = process(x, lsb, r, curr)
    n = length(x);
    noise = max(x)-min(x);
    m = sum(x)/n;
    s = std(x);
    noise99 = 6 * s;
    nlsb = s / lsb;
    
    tbl = tabulate(x);
    indices = tbl(:,2) == 0;
    tbl(indices,:) = [];

    tbl( all(~tbl,2), : ) = [];  %rows
    tbl( :, all(~x,1) ) = [];  %columns

    tbl = num2cell(tbl);
    t = cell2table(tbl, 'VariableNames', {'Value','Count','Percent'});
    t.Value = categorical(t.Value);
    
    
%     a = getGlobala;
%     set(0,'DefaultAxesTitleFontWeight','normal');
%     figure(a+1);
%     bar(t.Value, t.Count)
%     set(gcf, 'Position',  [100, 100, 1600, 900])
%     ylabel('Number of Samples', 'FontSize', 16);
%     xlabel('Measured Voltage (\muV)', 'FontSize', 16);
%     text = ['99.7% Noise = ', num2str(noise99), ' \muV, RMS Noise = ', num2str(s), ' \muV (', num2str(nlsb), ' LSB)'];
%     text2 = ['Pol. Current = ', num2str(curr), ' \muA , Resistor Value = ', num2str(r), ' \Omega'];
%     title({text, text2, ' '}, 'FontSize', 28);
%     
%     a = a + 1;
%     setGlobala(a);
    
    
end
function setGlobala(val)
    global a
    a = val;
end
function r = getGlobala
    global a
    r = a;
end
